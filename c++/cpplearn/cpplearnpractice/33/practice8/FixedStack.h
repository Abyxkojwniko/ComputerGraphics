#pragma once


#include <iostream>
#include <stdexcept>
#include <string>

template <typename T, std::size_t N>
class FixedStack{
private:
    T data[N];
    std::size_t top_index;
public:
    FixedStack() : top_index(0){};
    void push(const T& value){
        if(full()){
            throw std::overflow_error("Stack is full.");
        }
        data[top_index++] = value;
    }

    void pop(){
        if(empty()){
            throw std::underflow_error("Stack is empty.");
        }
        --top_index;
    }

    T& top(){
        if(empty()){
            throw std::underflow_error("Stack is empty.");
        }
        return data[top_index - 1];
    }

    bool empty() const noexcept {
        return top_index == 0;
    }

    bool full() const noexcept {
        return top_index == N;
    }

    std::size_t size() const noexcept {
        return top_index;
    }

    constexpr std::size_t capacity() const noexcept {
        return N;
    }
};