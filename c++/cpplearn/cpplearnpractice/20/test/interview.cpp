#include "interview.h"

int JoiningThread::GetIndex() const{
    return _i;
}

JoiningThread::JoiningThread(){
    _i=0;
}

JoiningThread::JoiningThread(int i):_i(i){

}

JoiningThread::JoiningThread(const JoiningThread& other){
    _i=other._i
    
}