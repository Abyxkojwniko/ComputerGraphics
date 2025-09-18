#include "Triple.h"

int main(){
    int a = 10, b = 5, c = 3;
    Triple<int> tr1(a, b, c);
    tr1.print();
    std::string s1 = "hello", s2 = "world", s3 = "cpp";
    Triple<std::string> tr2(s1, s2, s3);
    tr2.print();
    return 0;
}