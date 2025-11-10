#include "Singleton.h"
#include <thread>
#include <mutex>


int main(){
    // std::cout << "s1 addr is" << &Singleton::GetInst() << std::endl;
    // std::cout << "s2 addr is" << &Singleton::GetInst() << std::endl;
    std::mutex mtx;
    std::thread t1([&](){
        SingleHungry::GetInst();
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "s1 addr is" << SingleHungry::GetInst() << std::endl;
    });

    std::thread t2([&](){ 
        SingleHungry::GetInst();
        mtx.lock();
        std::cout << "s2 addr is" << SingleHungry::GetInst() << std::endl;
        mtx.unlock();
    });

    t1.join();
    t2.join();   
    return 0;
}