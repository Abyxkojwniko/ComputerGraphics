#pragma once

#include <iostream>

// 定义类型列表模板
template <typename... Ts>
struct TypeList {};

// 主模板声明
template <typename List>
struct LengthOf;

// 针对 TypeList 的特化实现
template <typename... Ts>
struct LengthOf<TypeList<Ts...>> {
    static constexpr std::size_t value = sizeof...(Ts);
};