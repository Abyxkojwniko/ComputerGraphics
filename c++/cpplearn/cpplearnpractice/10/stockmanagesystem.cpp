#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

struct Stock{
    int id;
    std::string name;
    int num;
    void printstockinfo() const{
        //这里的const表示不能通过这个函数修改这个struct中的任何成员变量
        //要养成给任何只读函数加const的习惯
        std::cout<<"the stock's id is "<<id
            <<",name is "<<name
            <<",num is "<<num<<std::endl;
    }
};

void addStock(std::vector<Stock>&stocks){
    Stock s={};
    std::cout<<"please input the stock's id"<<std::endl;
    std::cin>>s.id;
    std::cout<<"please input the stock's name"<<std::endl;
    std::cin>>s.name;
    std::cout<<"please input the stock's num"<<std::endl;
    std::cin>>s.num;
    stocks.push_back(s);
    std::cout<<"add successfully"<<std::endl;
}

void deleteStock(std::vector<Stock>&stocks){
    int id;
    std::cout<<"please input the id you want to delete"<<std::endl;
    std::cin>>id;
    //这里的id表示从外部获取的变量
    auto it=std::find_if(stocks.begin(),stocks.end(),[id](const Stock& s){
        return s.id==id;
    });
    if(it!=stocks.end()){
        stocks.erase(it);
        std::cout<<"delete successfully"<<std::endl;
    }
    else{
        std::cout<<"cant find the id "<<id<<std::endl;
    }
}

void updateStock(std::vector<Stock>&stocks){
    int id;
    std::cout<<"please input the stock's id you want to update"<<std::endl;
    std::cin>>id;
    auto it=std::find_if(stocks.begin(),stocks.end(),[id](const Stock& s){
        return s.id==id;
    });
    if(it!=stocks.end()){
        std::cout<<"please input the num you change"<<std::endl;
        std::cin>>(*it).num;
        std::cout<<"update successfully"<<std::endl;
    }
    else{
        std::cout<<"cant find the id "<<id<<std::endl;
    }
}

void showStocksinfo(const std::vector<Stock> stocks){
    if(stocks.empty()) std::cout<<"no stock here"<<std::endl;
    for(auto stock:stocks){
        stock.printstockinfo();
        std::cout<<std::endl;
    }
}

int main(){
    std::vector<Stock> stocks;
    int choice;
    do{
        std::cout<<"zhis is stock manage system,please choice the function you need"<<std::endl;
        std::cout<<"1.add stock"<<std::endl;
        std::cout<<"2.show all stock"<<std::endl;
        std::cout<<"3.update stock by id"<<std::endl;
        std::cout<<"4.delete stock by id"<<std::endl;
        std::cout<<"5.exit"<<std::endl;
        std::cout<<"please choose from 1-5"<<std::endl;
        std::cin>>choice;
        if(choice==1){
            addStock(stocks);
        }
        else if(choice==2){
           showStocksinfo(stocks);
        }
        else if(choice==3){
            updateStock(stocks);
        }
        else if(choice==4){
            deleteStock(stocks);
        }
        else if(choice==5){
            std::cout<<"exit the system"<<std::endl;
        }
        else{
            std::cout<<"meaningless choice,please choose again"<<std::endl;
        }
    }while(choice!=5);
    return 0;
}