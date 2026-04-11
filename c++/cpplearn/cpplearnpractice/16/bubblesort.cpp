/*
编写一个 C++ 程序，使用 **冒泡排序算法** 对用户输入的一组整数进行排序。冒泡排序是一种简单的排序算法，通过重复交换相邻的未按顺序排列的元素，将最大或最小的元素“冒泡”到序列的一端。

### **要求**

1. **输入**：用户输入一组整数，首先输入整数的数量 `n`，然后输入 `n` 个整数。
2. **排序**：使用冒泡排序算法对输入的整数进行升序排序。
3. **输出**：显示排序前和排序后的整数序列。
4. **函数封装**：将冒泡排序算法封装在一个独立的函数中，提高代码的模块化和可读性。

*/
#include<iostream>
#include<vector>

std::vector<int> BubbleSort(const std::vector<int> nums,int n){
    std::vector<int> ans=nums;
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(ans[j]<ans[j-1]){
                std::swap(ans[j], ans[j-1]);
            }
        }
    }
    return ans;
}
void show(std::vector<int> nums,int n){
    for(int i=0;i<n;i++) std::cout<<nums[i]<<" ";
    std::cout<<std::endl;
}
int main(){
    std::cout<<"please input the number of the array you want sort"<<std::endl;
    int n;
    std::cin>>n;
    std::cout<<"please input the num in the array"<<std::endl;
    std::vector<int> nums;
    for(int i=0;i<n;i++){
        int num;
        std::cin>>num;
        nums.push_back(num);
    }
    std::vector<int> ans;
    ans=BubbleSort(nums,n);
    std::cout<<"the before array is:"<<std::endl;
    show(nums,n);
    std::cout<<"the after array is:"<<std::endl;
    show(ans,n);
    return 0;
}