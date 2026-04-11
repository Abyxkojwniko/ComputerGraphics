import torch
from torch import nn
import matplotlib.pyplot as plt
import torch.optim
from tqdm import tqdm
from pathlib import Path
device="cuda" if torch.cuda.is_available() else "cpu"

def make_data(weight,bias,start,end,step):
    x=torch.arange(start,end,step).unsqueeze(1)
    y=weight*x+bias
    return x,y

def split(x,y,percentage):
    per=int(percentage*len(x))
    x_train,y_train=x[:per],y[:per]
    x_test,y_test=x[per:],y[per:]
    return x_train,x_test,y_train,y_test

def plot_show(x_train,x_test,y_train,y_test,predictions=None):
    plt.figure(figsize=(10,7))
    plt.scatter(x_train,y_train,c="b",s=4,label="training_data")
    plt.scatter(x_test,y_test,c="g",s=4,label="testing_data")
    if predictions is not None:
        plt.scatter(x_test,predictions,c="r",s=4,label="predictions")
    plt.legend(prop={"size":14})
    plt.show()

class LinearRegression(nn.Module):
    def __init__(self):
        super().__init__()
        self.w=nn.Parameter(torch.randn(1,
                            requires_grad=True,
                            dtype=torch.float))
        self.b=nn.Parameter(torch.randn(1,
                            requires_grad=True,
                            dtype=torch.float))
    def forward(self,x):
        return self.w*x+self.b


def train(x_train,y_train,x_test,y_test,loss_fn,optimizer,epochs,model):
    epoch_count=[]
    train_losses=[]
    test_losses=[]
    for epoch in tqdm(range(epochs)):
        model.train()
        preds=model(x_train)
        train_loss=loss_fn(preds,y_train)
        optimizer.zero_grad()
        train_loss.backward()
        optimizer.step()
        model.eval()
        with torch.inference_mode():
            test_preds=model(x_test)
            test_loss=loss_fn(test_preds,y_test)
        if(epoch%10==0):
            epoch_count.append(epoch)
            train_losses.append(train_loss.detach().cpu().numpy())
            test_losses.append(test_loss.detach().cpu().numpy())
            print(f"Epoch:{epoch} | Loss:{train_loss} | Test loss:{test_loss}")   
    path=Path("model_parameters")
    path.mkdir(parents=True,exist_ok=True)
    model_name="model.pth"
    model_save_path=path/model_name
    torch.save(model.state_dict(),model_save_path)
    return model

if __name__=="__main__":
    model=LinearRegression()
    model_save_path="pytorch基础\pytorch起步\pytorchworkflow\model_parameters\model_0.pth"
    model.load_state_dict(torch.load(f=model_save_path))
    model.eval()
    