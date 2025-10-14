#include "template.h"


int main(){
    // std::cout << maxValue(1, 2) << std::endl;
    // std::cout << maxValue(1.1, 2.8) << std::endl;
    // std::cout << maxValue('a', 'b') << std::endl;
    // std::cout << maxValue("abc", "def") << std::endl;

    // Pair<int, float> p1(1, 2.8);
    // p1.print();

    // FixedArray<int, 5> arr;
    // for(int i = 0; i < 5; ++i){
    //     arr[i] = i;
    // }
    // arr.print();

    // ContinerPrinter<std::vector, int> VectorPrint;
    // std::vector<int> vec = {1, 2, 3, 4, 5};
    // VectorPrint.print(vec);

    // ContinerPrinter<std::list, int> ListPrint;
    // std::list<int> l1 = {10, 20, 30};
    // ListPrint.print(l1);

    Printer<int> intPrinter;
    intPrinter.print(10);
    Printer<std::string> strPrinter;
    strPrinter.print("hello"); 
    int a = 10;
    int* b = &a;
    Pair<int, int*> Pair1(15, b);
    std::cout << "A address: " << &a << std::endl;
    Pair1.print();
    std::cout << "---------------------------------------------" << std::endl;
    printValue(10);
    std::string s1 = "Hello World C++ Template";
    printValue(s1);
    printValue(b);
    printAll(1, 2.5, "hello", 'A');
    coutAll(10, 20, 10.5, "abc");
    std::cout << "Sum is : " << std::fixed << std::setprecision(10)  << sumAll(1.0, 2.5, 3.66, 1354, 114514) << std::endl;
    return 0;
}