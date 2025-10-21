#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
#include <type_traits>
#include <concepts>
#include <vector>

template<typename T>
concept SizedContainer = requires(const T& c){
    {c.size()} -> std::integral;
};



template<SizedContainer T>
void enableIfExample(const T& container) {
    std::cout << "Container has size: " << container.size() << std::endl;
}
