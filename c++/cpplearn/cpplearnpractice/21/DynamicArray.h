#pragma once

#include<iostream>

class DynamicArray {
public:
    DynamicArray();
    DynamicArray(size_t capacity, size_t size, int* data);
    ~DynamicArray();
    void add(int value);
    int get(size_t index);
    size_t getSize() const;
    size_t getCapacity() const;
    friend std::ostream& operator <<(std::ostream& out, DynamicArray &array);
private:
    void resize(size_t new_capacity);
    std::size_t _capacity;
    std::size_t _size;
    int *_data;
};