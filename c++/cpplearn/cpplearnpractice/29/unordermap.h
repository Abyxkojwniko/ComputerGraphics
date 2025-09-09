#pragma once
#include <iostream>
#include <vector>
#include <functional>

template <typename T>
struct Point{
    T x;
    T y;
    bool operator==(const Point<T>& other) const{
        return other.x == x && other.y == y;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Point<T>& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

template <typename T>
struct PointHash{
    std::size_t operator()(const Point<T>& p) const noexcept{
        std::size_t h1 = std::hash<T>()(p.x);
        std::size_t h2 = std::hash<T>()(p.y);
        return h1 ^ (h2 << 1);
    }
};

template <typename T>
struct PointEqual{
    std::size_t operator()(const Point<T>& p1, const Point<T>& p2){
        return p1.x == p2.x && p1.y == p2.y;
    }
};

template<typename KeyName, typename ValueName>
class unordermap{
    KeyName key;
    std::vector<ValueName> value;
};