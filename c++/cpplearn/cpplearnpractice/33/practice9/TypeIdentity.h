#pragma once

#include <type_traits>

// 定义模板类 TypeIdentity
template <typename T>
struct TypeIdentity {
    using type = T;  // 成员类型 type 等同于模板参数 T
};

// 使用 static_assert 验证类型关系
static_assert(std::is_same_v<TypeIdentity<int>::type, int>, 
              "TypeIdentity<int>::type must be int");
static_assert(std::is_same_v<TypeIdentity<double>::type, double>,
              "TypeIdentity<double>::type must be double");
static_assert(std::is_same_v<TypeIdentity<char>::type, char>,
              "TypeIdentity<char>::type must be char");