#pragma once

#include<iostream>
#include <thread>
class JoiningThread{
public:
    JoiningThread();
    JoiningThread(int i);
    JoiningThread(const JoiningThread& other);


    int GetIndex() const;


private:
    std::thread _t;
    int _i;
};