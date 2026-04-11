#include<iostream>

int count(unsigned int n){
    int cnt = 0;
    while(n){
        n &= n-1;
        cnt++;
    }
    return cnt;
}

int main(){
    int n, m;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> m;
        int cnt = count(m);
        std::cout << cnt << " ";
    }
    return 0;
}