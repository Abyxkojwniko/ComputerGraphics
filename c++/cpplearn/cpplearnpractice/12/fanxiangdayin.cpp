/*
2 反向打印
描述：编写一个程序，从用户输入一组整数到一个 `std::vector` 中，然后使用迭代器反向打印这些元素。
*/

#include<iostream>
#include<vector>

int main(){
    std::vector<int> nums;
    int num;
    std::cout<<"please input the num and end with -1"<<std::endl;
    while(std::cin>>num&&num!=-1){
        nums.push_back(num);
    }
    for(auto it=nums.end()-1;it!=nums.begin()-1;it--){
        std::cout<<(*it)<<" ";
    }
    //或者可以采用这种写法
    /*
    for (std::vector<int>::reverse_iterator it = numbers.rbegin(); it != numbers.rend(); ++it) {
        std::cout << *it << " ";
    }
    */
    std::cout<<std::endl;
    return 0;
}