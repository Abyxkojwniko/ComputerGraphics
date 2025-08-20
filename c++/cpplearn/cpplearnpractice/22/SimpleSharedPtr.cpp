#include "SimpleSharedPtr.h"
#include <iostream>
#include "Student.h"

ControlBlock::ControlBlock():ref_count(1){}

template <typename T>
void SimpleSharedPtr<T>::release(){
    if(control){
        -- control -> ref_count;
        if(control->ref_count == 0){
            delete ptr;
            ptr = nullptr;
            delete control;
            control = nullptr;
        }
    }
}

template <typename T>
SimpleSharedPtr<T>::SimpleSharedPtr():ptr(nullptr), control(nullptr){}

template <typename T>
SimpleSharedPtr<T>::~SimpleSharedPtr(){
    if(ptr){
        release();
    }
}

template <typename T>
SimpleSharedPtr<T>::SimpleSharedPtr(T *p):ptr(p){
    if(p){
        control = new ControlBlock();
    }else{
        control = nullptr;
    }
}

template <typename T>
SimpleSharedPtr<T>::SimpleSharedPtr(const SimpleSharedPtr& other):ptr(other.ptr), control(other.control){
    if(control){
        ++ control ->ref_count;
    }
}

template <typename T>
SimpleSharedPtr<T>& SimpleSharedPtr<T>::operator=(const SimpleSharedPtr& other){
    if(this != &other){
        release();
        ptr = other.ptr;
        control = other.control;
        if(control){
            ++ control -> ref_count;
        }
    }
    return *this;
}

template <typename T>
SimpleSharedPtr<T>::SimpleSharedPtr(SimpleSharedPtr&& other) noexcept : ptr(other.ptr), control(other.control) {
    other.ptr = nullptr;
    other.control = nullptr;
}

template <typename T>
SimpleSharedPtr<T>& SimpleSharedPtr<T>::operator=(SimpleSharedPtr&& other) noexcept {
    if(this != &other){
        release();
        ptr = other.ptr;
        control = other.control;
        other.ptr = nullptr;
        other.control = nullptr;
    }
    return *this;
}

template <typename T>
T* SimpleSharedPtr<T>::operator->() const{
    return ptr;
}

template <typename T>
T& SimpleSharedPtr<T>::operator*() const{
    return *ptr;
}

template <typename T>
T* SimpleSharedPtr<T>::get() const{
    return ptr;
}

template <typename T>
int SimpleSharedPtr<T>::use_count() const{
    return control ? control->ref_count : 0;
}

template <typename T>
void SimpleSharedPtr<T>::reset(T* p){
    release();
    ptr = p;
    if(p){
        control = new ControlBlock();
    }else{
        control = nullptr;
    }
}


template class SimpleSharedPtr<int>;
template class SimpleSharedPtr<double>;
template class SimpleSharedPtr<std::string>;
template class SimpleSharedPtr<Student>;