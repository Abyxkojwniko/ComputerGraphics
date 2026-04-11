#pragma once

struct ControlBlock{
    int ref_count;
    ControlBlock();
};

template <typename T>
class SimpleSharedPtr {
private:
    T *ptr;
    ControlBlock *control;
    void release();
public:
    SimpleSharedPtr();

    ~SimpleSharedPtr();

    explicit SimpleSharedPtr(T *p);

    SimpleSharedPtr(const SimpleSharedPtr& other);

    SimpleSharedPtr& operator=(const SimpleSharedPtr& other);

    SimpleSharedPtr(SimpleSharedPtr&& other) noexcept;

    SimpleSharedPtr& operator=(SimpleSharedPtr&& other) noexcept;

    T* operator->() const;

    T& operator*() const;

    T* get() const;

    int use_count() const;

    void reset(T* p);
};