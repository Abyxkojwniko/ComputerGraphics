#pragma once

#include <iostream>
#include <mutex>

class Singleton{
public:
    ~Singleton(){
        std::cout << "Single destructed" << std::endl;
    };

    static Singleton& GetInst(){
        static Singleton single;
        return single;
    }
private:
    Singleton(){};
    Singleton(const Singleton&) = delete;
    Singleton& operator = (const Singleton&) = delete;
};


class SingleHungry{
private:
    SingleHungry(){};
    SingleHungry(const SingleHungry&) = delete;
    SingleHungry& operator = (const SingleHungry&) = delete;
    static SingleHungry *single;
public:
    ~SingleHungry(){
        std::cout << "SingleHungry destructed" << std::endl;
    }
    static SingleHungry* GetInst(){
        std::lock_guard<std::mutex> lock(_mtx);
        if(single == nullptr){
            single = new SingleHungry();
        }
        return single;
    }
    static std::mutex _mtx;
};

class SingelPointer{
private:
    SingelPointer(){};
    SingelPointer(const SingelPointer&) = delete;
    SingelPointer& operator = (const SingelPointer&) = delete;
    static SingelPointer * single;
    static std::mutex s_mutex;

public:
    ~SingelPointer(){
        std::cout << "SinglePointer destructed" << std::endl;
    }
    static SingelPointer* GetInst(){
        if(single != nullptr){
            return single;
        }
        s_mutex.lock();
        if(single != nullptr){
            s_mutex.unlock();
            return single;
        }
        single = new SingelPointer();
        s_mutex.unlock();
        return single;
    }
};