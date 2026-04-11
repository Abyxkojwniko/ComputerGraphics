#pragma once

#include <iostream>
#include <type_traits>

template <typename T>
class TypeIdentity{
public:
    using type = T;
};