#include "Template.h"

int main(){
    Printer<int> intPrinter;
    Printer<int *> iPrinter;
    intPrinter.print(10);
    int b = 5;
    int *a = &b;
    iPrinter.print(a);
    double value = 10.5;
    Pair<std::string, double*> p1("abc", &value);
    p1.print();
    printValue(42);
    std::string str1 = "12dhakekhpaje";
    printValue<std::string>(str1);
    printValue(&b);

    printAll(10, &b, "abc");
    countAll(10, &a, "dhkal");
    std::cout << sum(1, 2, 3, 4) << std::endl;
    std::cout << sum(1.5, 2.3, 3.7, 4.4) << std::endl;


    std::cout << allNot(false, false, true) << std::endl;
    std::cout << sumLeftFold(1, 2, 3, 4, 5) << std::endl;
    std::cout << sumrightFold(1, 2, 3, 4) << std::endl;
    std::cout << multiRightFlod(1, 2, 3, 4) << std::endl;
    printFoldAll(1, 2, 3, 4);

    MyPoint point1(1, 2), point2(3, 4), point3(5, 6);
    auto result = sumPoints(point1, point2, point3);
    std::cout << result.x << " " << result.y << std::endl;
    return 0;
}