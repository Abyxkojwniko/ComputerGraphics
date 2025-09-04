#include <iostream>
#include "template.h"
#include <vector>
#include <list>

int main(){
    // std::cout << maxvalue(1, 4) << std::endl;
    // std::cout << maxvalue(1.1, 4.8) << std::endl;
    // std::cout << maxvalue('a', 'b') << std::endl;
    // std::cout << maxvalue("abc", "def") << std::endl;
    Pair<int, int> p1(1, 2);
    p1.print();
    std::vector<int> v1;
    Pair<double, int> p2(1.55, 2);
    p2.print();

    FixedArray<int, 5> arr;
    for(int i = 0; i < 5; ++i){
        arr[i] = i * 10;
    }
    arr.print();

    ContainerPrinter<std::vector, int> vecPrinter;
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vecPrinter.print(vec);
    ContainerPrinter<std::list, int> listPrinter;
    std::list<int> list = {10, 20, 30, 40, 50};
    listPrinter.print(list);
    return 0;
}