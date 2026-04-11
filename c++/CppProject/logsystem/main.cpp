#include <iostream>
#include <thread>
#include <condition_variable>
#include <queue>
#include <string>
#include <mutex>
#include <atomic>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <fstream>

template<typename T>
std::string to_string_helper(T&& arg){
    std::ostringstream oss;
    oss << std::forwad<T>(arg);
    return oss.str();
}


int main(){
    std::cout << "Hello World!" << std::endl;
    return 0;
}