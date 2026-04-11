#pragma once
#include<iostream>

template <typename T>
class Complex{
public:
    Complex(T re = 0, T im = 0): re(re), im(im){}
    Complex(const Complex& other) = default;
    Complex& operator += (const Complex<T> &other);
    Complex& operator -= (const Complex<T> &other);
    Complex<T> operator + (const Complex<T> &other) const;
    Complex<T> operator - (const Complex<T> &other) const;
    Complex<T> operator * (const Complex<T> &other) const;
    const T& real() const { return re; }
    const T& img() const { return im; }
    friend std::ostream& operator <<(std::ostream& os, const Complex<T>& c){
        if (c.im < 0) 
            os << c.re << c.im << "i"; 
        else 
            os << c.re << "+" << c.im << "i";
        return os;
    }
private:
    T re;
    T im;

};


template<typename T>
Complex<T>& Complex<T>::operator+=(const Complex<T>& other){
    this->re += other.re;
    this->im += other.im;
    return *this;
}

template<typename T>
Complex<T>& Complex<T>::operator-=(const Complex<T>& other){
    this->re -= other.re;
    this->im -= other.im;
    return *this;
}

template<typename T>
Complex<T> Complex<T>::operator + (const Complex<T>& other) const{
    Complex<T> result(*this); // 拷贝构造
    result += other;          // 复用完美的 +=
    return result;
}
template<typename T>
Complex<T> Complex<T>::operator - (const Complex<T>& other) const{
    Complex<T> result(*this);
    result -= other;
    return result;
}
template<typename T>
Complex<T> Complex<T>::operator*(const Complex<T>& other) const {
    return Complex<T>(
        this->re * other.re - this->im * other.im,
        this->re * other.im + this->im * other.re
    );
}
