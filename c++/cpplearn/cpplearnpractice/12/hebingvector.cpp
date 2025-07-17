/*
3 合并两个 `vector`
描述：编写一个程序，创建两个 `std::vector`，从用户输入填充它们。使用迭代器将这两个 `vector` 合并为一个新 `vector`。

*/

#include<iostream>
#include<vector>

int main(){
    std::vector<int> v1,v2,mergedvector;
    std::cout<<"please input the num in vector one and end with -1"<<std::endl;
    int num;
    while(std::cin>>num&&num!=-1){
        v1.push_back(num);
    }
    std::cout<<"please input the num in vector two and end with -1"<<std::endl;
    while(std::cin>>num&&num!=-1){
        v2.push_back(num);
    }
    mergedvector.insert(mergedvector.end(),v1.begin(),v1.end());
    mergedvector.insert(mergedvector.end(),v2.begin(),v2.end());
    for(auto it=mergedvector.begin();it!=mergedvector.end();it++){
        std::cout<<(*it)<<" ";
    }
    std::cout<<std::endl;
    return 0;
}