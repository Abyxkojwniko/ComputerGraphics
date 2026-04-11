#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T, std::size_t N>
class FixedStack{
private:
    std::vector<T> st;
    std::size_t index;
public:
    FixedStack():st(N), index(0){};
    bool empty() const{
        return index == 0;
    }
    bool full() const{
        return index == N;
    }
    void push(const T& value){
        if(full()){
            throw std::out_of_range("Error: FixedStack is full.");
        }
        st[index++] = value;
    }
    void pop(){
        if(st.empty()){
            throw std::out_of_range("Error: FixedStack is empty. Cannot pop.");
        }
        --index;
    }
    const T& top() const{
        if(st.empty()){
           throw std::out_of_range("Error: FixedStack is empty. Cannot top.");
        }
        return st[index-1];
    }
    std::size_t size() const{
        return index;
    }
};
