/*
构建一个简单的事件系统，允许用户注册多个回调函数（函数指针或Lambda表达式），并在特定事件触发时调用这些回调函数。
*/
#include<iostream>
#include<vector>
#include<functional>

using Callback =std::function<void(int)>;

class EventSystem{
private:
    std::vector<Callback> callbacks;
public:
    void registerCallback(const Callback &cb){
        callbacks.push_back(cb);
    }
    void triggerEvent(int data){
        std::cout<<"Event with data="<<data<<". executing callbacks.."<<std::endl;
        for(auto&cb:callbacks){
            cb(data);
        }
    }
};
void onEvent(int data){
    std::cout<<"function callback received data:"<<data<<std::endl;
}

int main() {
    EventSystem eventSystem;
    // 注册基于函数指针的回调
    eventSystem.registerCallback(onEvent);
    // 注册基于Lambda表达式的回调
    eventSystem.registerCallback([](int x) {
        std::cout << "Lambda callback received: " << x * 2 << std::endl;
    });
    // 注册带捕获的Lambda表达式的回调
    int multiplier = 5;
    eventSystem.registerCallback([multiplier](int x) {
        std::cout << "Lambda with capture received: " << x * multiplier << std::endl;
    });
    // 触发事件，传递参数
    eventSystem.triggerEvent(10);
    return 0;
}
