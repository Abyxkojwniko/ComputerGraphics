#include "DynamicArray.h"

DynamicArray::DynamicArray()
    :_capacity(2), _size(0), _data((int*)malloc(_capacity*sizeof(int))){
}

DynamicArray::DynamicArray(size_t capacity, size_t size, int* data)
    :_capacity(capacity), _size(size), _data((int*)malloc(capacity*sizeof(int))){
    if(!data){
        std::cerr << "malloc fail" << std::endl;
        throw std::bad_alloc{};
    }
}

DynamicArray::~DynamicArray(){
    free(_data);
}

void DynamicArray::resize(size_t new_capacity){
    int *temp =(int*)realloc(_data, new_capacity*sizeof(int));
    if(!temp){
        std::cerr << "malloc fail" << std::endl;
        throw std::bad_alloc{};
    }
    _data = temp;
    _capacity  =new_capacity;
}

void DynamicArray::add(int value){
    if(_size == _capacity){
        resize(_capacity*2);
    }
    _data[_size++] = value;
}

int DynamicArray::get(size_t index){
    if(index >= _size){
        throw std::out_of_range("index out of range");
    }
    return _data[index];
}

size_t DynamicArray::getSize() const{
    return _size;
}

size_t DynamicArray::getCapacity() const{
    return _capacity;
}

std::ostream& operator<<(std::ostream& out, DynamicArray& array){
    out << "the capacity is:" << array.getCapacity()
    << ", the size is:" << array.getSize()<< "\nElements:";
    for(size_t i = 0; i < array.getSize(); i++){
        out << array.get(i) << " ";
    }
    return out;
}