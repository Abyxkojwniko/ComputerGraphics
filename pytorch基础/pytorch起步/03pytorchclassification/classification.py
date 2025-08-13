import torch
import matplotlib.pyplot as plt
from tqdm import tqdm
import torch.nn as nn
import sklearn
from sklearn.datasets import make_circles
from sklearn.model_selection import train_test_split
from pathlib import Path

device="cuda" if torch.cuda.is_available() else "cpu"

def make_data(n):
    x,y=make_circles(n,noise=0.03,random_state=42)
    x=torch.from_numpy(x).type(torch.float32)
    y=torch.from_numpy(y).type(torch.float32)
    x_train,x_test,y_train,y_test=train_test_split(x,y,test_size=0.2,random_state=42,shuffle=True)
    return x_train,x_test,y_train,y_test

def plot_show(x_train,x_test,y_train,y_test,predictions=None):
    plt.figure(figsize=(10,7))
    plt.scatter(x_train[:, 0], x_train[:, 1], c=y_train, cmap=plt.cm.RdYlBu, s=4, label="training_data")
    plt.scatter(x_test[:, 0], x_test[:, 1], c=y_test, cmap=plt.cm.RdYlBu, s=4, label="testing_data")
    if predictions is not None:
        plt.scatter(x_test[:, 0], x_test[:, 1], c=predictions, cmap=plt.cm.RdYlBu, s=4, label="predictions")
    plt.legend(prop={"size":14})
    plt.show()

class CircleModel(nn.Module):
    def __init__(self):
        super().__init__()
        self.layer1=nn.Linear(in_features=2,out_features=128,bias=True)
        self.relu=nn.ReLU()
        self.layer2=nn.Linear(in_features=128,out_features=4,bias=True)  # 4 output units for 4 classes
        self.softmax=nn.Softmax(dim=1)  # Softmax for probability distribution
    def forward(self,x):
        x=self.layer1(x)
        x=self.relu(x)
        x=self.layer2(x)
        x=self.softmax(x)  # Apply softmax to get probabilities
        return x
    
def Train(x_train,x_test,y_train,y_test,loss_fn,optimizer,epochs,model):
    epoch_count=[]
    train_losses=[]
    test_losses=[]
    acces=[]
    for epoch in tqdm(range(epochs)):
        model.train()
        preds=model(x_train).squeeze()
        train_loss=loss_fn(preds,y_train)
        optimizer.zero_grad()
        train_loss.backward()
        optimizer.step()
        model.eval()
        with torch.inference_mode():
            logits=model(x_test).squeeze()
            test_loss=loss_fn(logits,y_test)
            preds=torch.argmax(logits, dim=1)  # Get class with highest probability
            acc=accuracy_fn(preds,y_test)
            if acc==100:break
            torch.save(model.state_dict(),"pytorch起步/03pytorchclassification/model_parameters/best_model_py.pth")
        if(epoch%10==0):
            epoch_count.append(epoch)
            train_losses.append(train_loss.detach().cpu().numpy())
            test_losses.append(test_loss.detach().cpu().numpy())
            print(f"Epoch:{epoch} | Loss:{train_loss} | Test loss:{test_loss}")  
    return model

def accuracy_fn(y_true,y_pred):
    correct=0
    correct += torch.eq(y_true, y_pred.to(y_true.device)).sum().item()
    acc=(correct/len(y_pred))*100
    return acc

if __name__=="__main__":
    model=CircleModel().to(device)
    epochs=1000
    x_train,x_test,y_train,y_test=make_data(1000)
    plot_show(x_train, x_test, y_train, y_test)
    x_train, y_train = x_train.to(device), y_train.to(device)
    x_test, y_test = x_test.to(device), y_test.to(device)
    loss_fn=nn.CrossEntropyLoss()  # Cross entropy loss for multi-class classification
    optimizer=torch.optim.SGD(params=model.parameters(),lr=0.2)
    best_model=Train(x_train,x_test,y_train,y_test,loss_fn,optimizer,epochs,model)
    y_preds = torch.argmax(model(x_test), dim=1).detach().cpu().numpy()  # Get predicted class
    x_train, y_train = x_train.to("cpu"), y_train.to("cpu")
    x_test, y_test = x_test.to("cpu"), y_test.to("cpu")
    plot_show(x_train, x_test, y_train, y_test,y_preds)

