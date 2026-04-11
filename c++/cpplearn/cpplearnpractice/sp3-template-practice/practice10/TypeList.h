#pragma once

#include <iostream>
#include <type_traits>
#include <string>
#include <vector>

template <typename ...Ts>
struct TypeList{};

template <typename List>
struct LengthOf{};

template <typename... Ts>
struct LengthOf<TypeList<Ts...>>{
    static constexpr std::size_t value = sizeof...(Ts);
};