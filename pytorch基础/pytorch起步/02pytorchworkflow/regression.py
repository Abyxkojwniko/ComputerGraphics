import torch
from torch import nn # nn contains all of PyTorch's building blocks for neural networks
import matplotlib.pyplot as plt
import torch.optim.sgd
from tqdm import tqdm

device="cuda" if torch.cuda.is_available() else "cpu"
print(device)

def make_data(weight,bias,start,end,step):
    x=torch.arange(start,end,step).unsqueeze(dim=1)
    y=weight*x+bias
    return x,y

def split(percentage,x,y):
    train_split=int(percentage*len(x))
    x_train=x[:train_split]
    y_train=y[:train_split]
    x_test=x[train_split:]
    y_test=y[train_split:]
    return x_train,y_train,x_test,y_test

def plot_show(train_data,train_labels,test_data,test_labels,predictions=None):
    plt.figure(figsize=(10,7))
    plt.scatter(train_data,train_labels,c="b",s=4,label="training_data")
    plt.scatter(test_data,test_labels,c="g",s=4,label="testing_data")
    if predictions is not None:
        plt.scatter(test_data,predictions,c='r',s=4,label="predictions")
    plt.legend(prop={"size":14})
    plt.show()


class LinearRegressionModel(nn.Module):
    def __init__(self):
        super().__init__()
        self.weights=nn.Parameter(torch.randn(1,
                                              requires_grad=True,
                                              dtype=torch.float))
        self.bias=nn.Parameter(torch.randn(1,
                                              requires_grad=True,
                                              dtype=torch.float))
        #self.linear=nn.linear(input_channel=1,output_channel=1)
    def forward(self,x):
        return self.weights*x+self.bias
    

def train(x_train,y_train,x_test,y_test,loss_fn,optimizer,epochs,model):
    epoch_count=[]
    train_losses=[]
    test_losses=[]
    for epoch in tqdm(range(epochs)):
        model.train()
        y_pred=model(x_train)
        loss=loss_fn(y_train,y_pred)
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        model.eval()
        with torch.inference_mode():
            test_preds=model(x_test)
            test_loss=loss_fn(test_preds,y_test)
        if epoch%10==0:
            epoch_count.append(epoch)
            train_losses.append(loss.detach().numpy())
            test_losses.append(test_loss.detach().numpy())
            print(f"Epoch:{epoch} | Loss:{loss} | Test loss:{test_loss}")        
    return model

if __name__ == "__main__":
    torch.manual_seed(42)
    model=LinearRegressionModel()
    weight,bias,start,end,step=0.7,0.3,0,1,0.02
    percentage=0.8
    x,y=make_data(weight,bias,start,end,step)
    x_train,y_train,x_test,y_test=split(percentage,x,y)
    plot_show(x_train,y_train,x_test,y_test)
    
    epoch=200
    loss_fn=nn.L1Loss()
    optimizer=torch.optim.SGD(params=model.parameters(),lr=0.05)
    model=train(x_train,y_train,x_test,y_test,loss_fn,optimizer,epoch,model)
    y_preds=model(x_test).detach().numpy() 
    plot_show(x_train,y_train,x_test,y_test,y_preds)