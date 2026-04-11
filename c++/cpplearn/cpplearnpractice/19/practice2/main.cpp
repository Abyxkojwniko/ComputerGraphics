#include "shape.h"
#include<vector>
#include <memory>

int main(){
    std::vector<std::unique_ptr<Shape>> vec;
    vec.emplace_back(std::make_unique<Circle>());
    vec.emplace_back(std::make_unique<Rectangle>());
    vec.emplace_back(std::make_unique<Shape>());
    for(auto& shape:vec){
        shape->draw();
    }
    return 0;
}