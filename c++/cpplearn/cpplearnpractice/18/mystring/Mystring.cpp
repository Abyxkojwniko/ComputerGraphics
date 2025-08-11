#include "Mystring.h"

Mystring::Mystring(const char*str){
    if(str==nullptr){
        _data=nullptr;
        return ;
    }
    _data=new char[strlen(str)+1];
    strcpy(_data,str);
    _data[strlen(str)]='\0';
}


Mystring::Mystring(const Mystring &other){
    if(other._data==nullptr){
        _data=nullptr;
        return ;
    }
    _data=new char[strlen(other._data)+1];
    strcpy(_data,other._data);
    _data[strlen(other._data)]='\0';
}

Mystring::Mystring(Mystring &&other){
    if(other._data==nullptr){
        _data=nullptr;
        return ;
    }
    _data=new char[strlen(other._data)+1];
    strcpy(_data,other._data);
    _data[strlen(other._data)]='\0';
}

Mystring& Mystring::operator=(const Mystring& other){
    if(this==&other)  return *this;
    if(other._data==nullptr){
        _data=nullptr;
        return *this;
    }
    _data=new char[strlen(other._data)+1];
    strcpy(_data,other._data);
    _data[strlen(other._data)]='\0';
    return *this;
}

Mystring& Mystring::operator=(Mystring &&other){
    if(this==&other)  return *this;
    if(other._data==nullptr){
        _data=nullptr;
        return *this;
    }
    *(_data)=std::move(*(other._data));
    return *this;
}

Mystring& Mystring::operator+(const Mystring& other){
    if(other._data==nullptr) return *this;
    char *temp=new char[strlen(_data)+strlen(other._data)+1];
    strcpy(temp,_data);
    strcat(temp,other._data);
    delete[] _data;
    _data=temp;
    return *this;
}

bool Mystring::operator==(const Mystring &other){
    if(other._data==nullptr){
        return _data==nullptr;
    }
    return strcmp(this->_data,other._data)==0;
}

std::ostream& operator<<(std::ostream& out,const Mystring &other){
    out<<"data is "<<other._data<<std::endl;
    return out;
}