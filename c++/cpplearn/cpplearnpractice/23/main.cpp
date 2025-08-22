#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <thread>

int (*funcPtr)(int, int);


int add(int a, int b){
    return a + b;
}

struct Adder{
    int to_add;
    Adder(int value): to_add(value){}
    int operator()(int x) const{
        return x + to_add;
    }
    void add(int x){
        to_add += x;
    }

};

struct IsGreaterThan{
    int threshold;
    IsGreaterThan(int value): threshold(value){}
    bool operator()(int x){
        return x > threshold;
    }
};

template<typename T>
struct Compare{
    bool operator()(const T&a, const T&b){
        return a < b;
    }
};

class Proceesor{
public:
    Proceesor(int threshold):_threshold(threshold){};
    void process(std::vector<int> &data){
        std::cout << "before process data" << std::endl;
        for (auto num : data){
            std::cout << num << " ";
        }
        std::cout << std::endl;
        auto new_end = std::remove_if(data.begin(), data.end(), [this](int n) -> bool{
            return n < _threshold;
        });
        data.erase(new_end, data.end());
        std::cout << "after process data" << std::endl;
        for (auto num : data){
            std::cout << num << " ";
        }
    }
private:
    int _threshold;
};

int main(){
    // funcPtr = &add;
    // //funcPtr = add;
    // int result = (*funcPtr)(1, 2);
    // std::cout << result << std::endl;
    // funcPtr(1, 2);


    // Adder adder(5);
    // std::cout << "5 + 10 = " << adder(10) << std::endl;

    // std::vector<int> numbers = {1,2,3,4,5,6};
    // IsGreaterThan greaterThan(10);
    // auto it = std::find_if(numbers.begin(), numbers.end(), greaterThan);
    // if(it != numbers.end()){
    //     std::cout << "found: " << std::endl;
    // }
    // else{
    //     std::cout << "not fount" << std::endl;
    // }


    // std::vector<double> numbers2 = {9.0,2.4,2.5,1.4,3.9};
    
    // std::sort(numbers2.begin(), numbers2.end(), Compare<double>());
    // for(auto& num : numbers2){
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;
    // return 0;
    // int threshold = 5;
    std::vector<int> numbers3 = {1, 2, 8, 6, 7 ,66 ,4};
    // auto new_end = std::remove_if(numbers3.begin(), numbers3.end(), [threshold](int x){
    //     return x < threshold;
    // });
    // numbers3.erase(new_end, numbers3.end());
    // for(auto& num : numbers3){
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    // int temp = 2;
    // auto lambda1 = [&](int x){
    //     temp *= x;
    // };
    // int *ptemp = &temp;
    // lambda1(2);
    // std::cout << temp << std::endl;
    // auto lambda2 = [ptemp](int x){
    //     *ptemp *= x;
    // };
    // lambda2(3);
    // std::cout << temp << std::endl;

    // auto add_ptr = std::make_shared<Adder>(10);
    // std::cout << add_ptr->to_add << std::endl;
    // auto lamda3 = [add_ptr](int x){
    //     (*add_ptr).add(x);
    //     //add_ptr->operator()(x);
    //     std::cout << add_ptr.use_count() << std::endl;
    // };
    // lamda3(5);
    // std::cout << add_ptr->to_add << std::endl;
    // std::thread t1;
    // {
    //     auto add_ptr = std::make_shared<Adder>(10);
    //     auto lamd3 = [add_ptr](int x){
    //         std::this_thread::sleep_for(std::chrono::seconds(10));
    //         add_ptr->add(x);
    //         std::cout << add_ptr.use_count() << std::endl;
    //     };
    //     std::thread t1(lamd3, 5);
    //     t1 = std::thread(lamd3, 5);
    // }
    // t1.join();

    Proceesor processor(5);
    processor.process(numbers3);
    return 0;   

}