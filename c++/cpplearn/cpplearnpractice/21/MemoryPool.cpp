#include "MemoryPool.h"

MemoryPool::MemoryPool(size_t objsize, size_t totalsize):
    _objsize(objsize), _totalsize(totalsize){
    _pool = (char*) malloc(objsize* totalsize);
    if(!_pool){
        throw std::bad_alloc();
    }
    for(size_t i = 0; i < totalsize; i++){
        _freeList.push(_pool+i*objsize);
    }
}

MemoryPool::~MemoryPool(){
    std::cout << "~MemoryPool" << std::endl;
    free(_pool);
}

void* MemoryPool::allocate(){
    if(_freeList.empty()){
        throw std::bad_alloc();
    }
    void *p=_freeList.top();
    _freeList.pop();
    return p;
}

void MemoryPool::deallocate(void *ptr){
    _freeList.push(ptr);
}