/*
 **编写一个递归函数，计算斐波那契数列的第n项**
*/

#include<iostream>

long long Fibonacci(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return Fibonacci(n-1)+Fibonacci(n-2);
}

int main() {
    int term = 10;
    long long result = Fibonacci(term);
    if(result != -1)
        std::cout << "Fibonacci(" << term << ") = " << result << std::endl;
    return 0;
}