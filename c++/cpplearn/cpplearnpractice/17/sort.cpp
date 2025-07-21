/*
**使用Lambda表达式和`std::sort`对一个字符串数组按长度排序**
给定一个字符串数组，使用Lambda表达式和`std::sort`函数对数组中的字符串按照其长度进行排序。
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main(){
    std::vector<std::string> fruits = {"apple", "banana", "kiwi", "strawberry", "grape", "pineapple"}; 
    std::sort(fruits.begin(),fruits.end(),[](const std::string &a,const std::string& b){
        return a.length()<b.length();
    });
    for(const auto &fruit:fruits){
        std::cout<<fruit<<" ";
    }
    std::cout<<std::endl;
    return 0;
}