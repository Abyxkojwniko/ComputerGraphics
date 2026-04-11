#include <iostream>
#include <vector> 
int N;
std::vector<int> array(10000000);

void QuickSort(std::vector<int>& array, int left, int right){
    if(left >= right) return;
    int index = array[left + (right - left) / 2], i = left - 1, j = right + 1;
    while(i < j){
        do ++i; while(array[i] < index);
        do --j; while(array[j] > index);
        if(i < j) std::swap(array[i], array[j]);
    }
    QuickSort(array, left, j);
    QuickSort(array, j + 1, right);
}

int main(){
    std::cin >> N;
    for(int i = 0; i < N; ++i){
        std::cin >> array[i];
    }
    QuickSort(array, 0, N - 1);
    for(int i = 0; i < N; ++i){
        std::cout << array[i] << " ";
    }
    return 0;
}