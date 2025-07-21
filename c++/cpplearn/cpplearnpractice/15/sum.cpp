/*
编写一个函数，接受 `std::vector<int>` 的迭代器范围，计算并返回范围内所有元素的和。
*/

#include<iostream>
#include<vector>

int sumRange(std::vector<int>::iterator start,std::vector<int>::iterator end){
    int sum=0;
    while(start!=end){
        sum+=*start;
        start++;
    }
    return sum;
}

int main() {
    std::vector<int> numbers = {2, 4, 6, 8, 10};
    int total = sumRange(numbers.begin(), numbers.end());
    std::cout << "Sum: " << total << std::endl;
    return 0;
}
