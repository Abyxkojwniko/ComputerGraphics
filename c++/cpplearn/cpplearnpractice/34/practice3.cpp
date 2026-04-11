#include <iostream>
#include <type_traits>
#include <utility> // std::forward

template<typename T>
void wrapper(T&& param) {
    // 问：forward_result 的最终类型是什么？
    //传入纯右值，T变为int，param应该是int&&，但是因为param是一个具名左值，所以最后是int&& &param，所以传入的是int&
    //但是因为使用了forward，T是int类型，所以param被强制转化为int&&变为右值引用，所以最后的结果应该是一个右值引用
    using ForwardResult = decltype(std::forward<T>(param));
    
    std::cout << "ForwardResult is rvalue reference: " << std::is_rvalue_reference<ForwardResult>::value << std::endl;
}

int main() {
    wrapper(20); // 传入纯右值
    return 0;
}