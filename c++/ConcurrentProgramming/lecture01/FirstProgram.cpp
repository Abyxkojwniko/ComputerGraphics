#include <iostream>
#include <thread>

void hello(){
    std::cout << "Hello ConCurrent World" << std::endl;
}

void do_something(){
    std::cout << "Hello ConCurrent World something" << std::endl;
}

void do_something_else(){
    std::cout << "Hello ConCurrent World something else" << std::endl;
}

class background_task{
public:
    void operator() () const{
        do_something();
        do_something_else();
    }
};

int main(){
    std::thread t(hello);
    if(t.joinable()){
        t.join();
    }
    //如何实例化一个对象，先初始化，加括号，使用大括号
    background_task f;
    std::thread my_thread(f);
    // std::thread my_thread((background_task()));
    // std::thread my_thread{background_task()};
    std::thread my_thread([]{do_something();do_something_else();});
    return 0;
}