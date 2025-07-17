/*
相邻元素的和

 编写一个程序，读取一组整数到一个 `std::vector` 中，并打印每对相邻元素的和。例如，给定输入 `1 2 3 4`，输出应为 `3 5 7`。
*/
#include<iostream>
#include<vector>

int main(){
    std::vector<int> ans;
    int num;
    std::cout<<"please input the number and end with -1"<<std::endl;
    while(std::cin>>num&&num!=-1){
        ans.push_back(num);
    }
    for(auto it =ans.begin();it+1!=ans.end();it++){
        std::cout<<((*it)+*(it+1))<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
