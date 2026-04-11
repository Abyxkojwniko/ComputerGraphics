#include <iostream>
#include "complex.h" 

using namespace std;

int main() {
    Complex<int> c1(3, 4);
    Complex<int> c2(1, -2);
    
    Complex<int> c3 = c1 + c2;
    Complex<int> c4 = c1 * c2;
    
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << c3 << endl;
    cout << "c1 * c2 = " << c4 << endl;
    
    return 0;
}