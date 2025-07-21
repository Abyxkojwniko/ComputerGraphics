/*
编写一个 C++ 程序，生成并显示斐波那契数列。程序应允许用户指定生成数列的长度，并使用 **循环结构** 或 **递归方法** 来生成斐波那契数。
斐波那契数列是一个由 0 和 1 开始，后续的每个数都是前两个数之和的数列。例如：0, 1, 1, 2, 3, 5, 8, 13, ...
1. **输入**：用户输入要生成的斐波那契数的数量 `n`。
2. **生成**：使用循环结构（如 `for` 或 `while` 循环）生成斐波那契数列。
3. **输出**：显示生成的斐波那契数列。
4. **函数封装**：将生成斐波那契数列的逻辑封装在一个独立的函数中。
*/

#include<iostream>
#include<vector>

void Fibonacci(std::vector<int>& nums,int n){
    int a=0,b=1;
    nums.push_back(a);
    nums.push_back(b);
    for(int i=2;i<n;i++){
        nums.push_back(a+b);
        int temp=b;
        b=a+b;
        a=temp;
    }
}

int main(){
    int n;
    std::cout<<"please input the number you want to generate"<<std::endl;
    std::cin>>n;
    if(n==1){
        std::cout<<"0"<<std::endl;
    }
    else if(n==2) {
        std::cout<<"0 1"<<std::endl;
    }
    std::vector<int> nums;
    Fibonacci(nums,n);
    for(int i=0;i<n;i++){
        std::cout<<nums[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}