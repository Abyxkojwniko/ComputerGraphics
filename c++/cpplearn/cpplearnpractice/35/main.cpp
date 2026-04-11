#include <iostream>
#include "Singleton.h"
#include <thread>
#include <mutex>


int main(){
    // std::cout << "s1 addr is: " <<  &Single2::GetInst() << std::endl;
    // std::cout << "s2 addr is: " <<  &Single2::GetInst() << std::endl;

    std::mutex mtx;
    std::thread t1([&](){
        Single2::GetInst();
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "s1 addr is " << &Single2::GetInst() << std::endl;
    });

    std::thread t2([&](){
        Single2::GetInst();
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "s1 addr is " << &Single2::GetInst() << std::endl;
    });

    t1.join();

    t2.join();

    return 0;
}