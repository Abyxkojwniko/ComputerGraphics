#include "ResourceManager.h"

int main(){
    ResourceManager rm1(42);
    std::cout << "Initial value is:" << rm1.getValue() << std::endl;

    rm1.setValue(20);
    std::cout << "Modified value is:" << rm1.getValue() << std::endl;

    ResourceManager rm2 = std::move(rm1);
    std::cout << "Moved value is:" << rm2.getValue() << std::endl;

    return 0;
}