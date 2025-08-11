#pragma once
#include <iostream>
#include <cstring>
class Mystring{
public:
    Mystring():_data(nullptr){};
    Mystring(const char* data);
    Mystring(const Mystring &other);
    Mystring(Mystring &&other);
    Mystring& operator=(const Mystring& other);
    Mystring& operator=(Mystring&& other);
    Mystring& operator+(const Mystring &other);
    bool operator == (const Mystring & other);
    friend std::ostream & operator <<(std::ostream &out,const Mystring &other);


private:
    char* _data;
};