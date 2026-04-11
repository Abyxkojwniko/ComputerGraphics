//
// Created by secon on 2025/3/1.
//

#ifndef DAY34_SINGLETON_SINGLETON_H
#define DAY34_SINGLETON_SINGLETON_H
#include <iostream>
#include <mutex>
#include <memory>

class Single2{
private:
    Single2(){};
    Single2(const Single2&)  =delete;
    Single2& operator=(const Single2&) = delete;
public:
    ~Single2(){
        std::cout << "Single2 destructed" << std::endl;
    };

    static Single2& GetInst(){
        static Single2 single;
        return single;
    }
};

class Single2Hungry{
private:
    Single2Hungry(){}
    Single2Hungry(const Single2Hungry&) = delete;
    Single2Hungry& operator=(const Single2Hungry&) = delete;
    static Single2Hungry *single;
public:
    ~Single2Hungry(){
        std::cout << "Single2Hungry destructed" << std::endl;
    }

    static Single2Hungry * GetInst(){

        if(single == nullptr){
            single = new Single2Hungry();
        }

        return single;
    }

};

class SinglePointer{
private:
    SinglePointer(){};
    SinglePointer(const SinglePointer&) = delete;
    SinglePointer& operator=(const SinglePointer&) = delete;
public:
    ~SinglePointer(){
        std::cout << "SinglePointer destructed" << std::endl;
    }

    static SinglePointer* GetInst(){
        if(single != nullptr){
            return single;
        }
        s_mutex.lock();
        if(single != nullptr){
            s_mutex.unlock();
            return single;
        }

        single = new SinglePointer();
        s_mutex.unlock();
        return single;
    }
private:
    static SinglePointer * single;
    static std::mutex s_mutex;
};

class SingleOnceFlag{
public:
    ~SingleOnceFlag(){
        std::cout << "SingleOnceFlag destructed" << std::endl;
    }

    static std::shared_ptr<SingleOnceFlag> GetInst(){
        static std::once_flag flag;
        std::call_once(flag, [](){
            _instance = std::shared_ptr<SingleOnceFlag>(new SingleOnceFlag());
        });

        return _instance;
    }
private:
    SingleOnceFlag() = default;
    SingleOnceFlag(const SingleOnceFlag&) = delete;
    SingleOnceFlag& operator=(const SingleOnceFlag&) = delete;
    static std::shared_ptr<SingleOnceFlag>  _instance;
};


class SingleAutoSafe;
class SafeDeletor
{
public:
    void operator()(SingleAutoSafe *sf)
    {
        std::cout << "this is safe deleter operator()" << std::endl;
        delete sf;
    }
};

class SingleAutoSafe{
public:
    static std::shared_ptr<SingleAutoSafe> getInstance(){
        static std::once_flag flag;
        std::call_once(flag, []{
            _instance = std::shared_ptr<SingleAutoSafe>(new SingleAutoSafe(), SafeDeletor());
        });
        return _instance;
    }

    void PrintAddress() {
        std::cout << _instance << std::endl;
    }
    //定义友元类，通过友元类调用该类析构函数
    friend class SafeDeletor;
private:
    SingleAutoSafe() = default;
    SingleAutoSafe(const SingleAutoSafe&) = delete;
    SingleAutoSafe& operator=(const SingleAutoSafe& st) = delete;
    ~SingleAutoSafe() {
        std::cout << "this is singleton destruct" << std::endl;
    }
    static std::shared_ptr<SingleAutoSafe> _instance;

};

template<typename T>
class Singleton{
protected:
    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    static std::shared_ptr<T>  _instance;
public:
    ~Singleton() = default;
    static std::shared_ptr<T> GetInst(){
        static std::once_flag flag;
        std::call_once(flag, []{
            _instance = std::shared_ptr<T>(new T());
        });
        return _instance;
    }
};

template<typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;

class SingleNet: public Singleton<SingleNet>{
    friend class Singleton<SingleNet>;
private:
    SingleNet() = default;
public:
    ~SingleNet(){
        std::cout << "SingleNet destructed" << std::endl;
    }
};
#endif //DAY34_SINGLETON_SINGLETON_H
