#pragma once
#include<iostream>
#include<stack>

class MemoryPool{
public:
    MemoryPool(size_t _objsize, size_t _totalsize);
    ~MemoryPool();
    void *allocate();
    void deallocate(void *ptr);

private:
    size_t _objsize;
    size_t _totalsize;
    char* _pool;
    std::stack<void*> _freeList;
};