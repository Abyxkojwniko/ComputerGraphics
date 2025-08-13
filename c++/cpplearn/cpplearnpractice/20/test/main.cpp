#include "interview.h"


int main(){
    // JoiningThread j1;
    // std::cout << "member _i is " << j1.GetIndex() << std::endl;
    JoiningThread j2(5);
    std::cout << "member _i is " << j2.GetIndex() << std::endl;
    return 0;
}