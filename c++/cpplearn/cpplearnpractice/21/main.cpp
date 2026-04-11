#include <iostream>
#include <cstdlib>
#include "Student.h"
#include "DynamicArray.h"
#include "MemoryPool.h"

int main(){
    //分配一个整数内存
    int *p = (int *)malloc(sizeof(int));
    if(!p){
        std::cerr << "Memory allocation failed!" << std::endl;
        return -1;
    }
    *p = 42;
    std::cout << "Value: " << *p << std::endl;
    free(p);


    // Student *st_p = (Student*)(sizeof(Student));
    // if(!st_p){
    //     std::cerr << "Memory allocation failed!" << std::endl;
    //     return -1;        
    // }
    // std::cout << "student age is: " << st_p->age <<",age is: " << st_p->name << std::endl;
    // free(st_p);


    int * array = (int *)malloc(5*sizeof(int));
    if(!array){
        std::cerr << "Memory allocation failed!" << std::endl;
        return -1;
    }
    for(int i = 0; i < 5; i++){
        //array[i] = i*2;
        *(array + i) = i*2;
        std::cout << "array["<< i <<"] is: " << array[i] << std::endl;
    }
    free(array);

    
    Student* p_st = new Student("Tom", 20);
    if(!p_st){
        std::cerr << "Memory allocation failed!" << std::endl;
        return -1;
    }
    std::cout << "student name is: " << p_st->GetName() << ", age is: " << p_st->GetAge() << std::endl;
    delete p_st;

    Student* pst_array = new Student[2]{
        {"tom", 20},
        {"jack", 18}
    };
    
    for(int i = 0; i < 2; i++){
        //std::cout << "student name is: " << (pst_array+i)->GetName() << ", age is: " << (pst_array+i)->GetAge() << std::endl;
        std::cout << "student name is: " << pst_array[i].GetName() << ", age is: " << pst_array[i].GetAge() << std::endl;
    }
    delete[] pst_array;

    int *arr = (int*)malloc(sizeof(int)*3);
    std::cout << "the address is: " << arr <<std::endl;
    if(!arr){
        std::cerr << "Memory allocation failed!" << std::endl;
        return -1;
    }
    for(int i = 0; i < 3; i++){
        //array[i] = i*2;
        *(array + i) = i*2;
        std::cout << "array["<< i <<"] is: " << array[i] << std::endl;
    }

    arr =(int*)realloc(arr, 5*sizeof(int));
    if(!arr){
        std::cerr << "Memory allocation failed!" << std::endl;
        free(arr);
        return -1;
    }
    for(int i = 3; i < 5; i++){
        //array[i] = i*2;
        *(array + i) = i*2;
        std::cout << "array["<< i <<"] is: " << array[i] << std::endl;
    }

    std::cout << "the address is: " << arr <<std::endl;
    free(arr);

    try{
        DynamicArray arr;
        arr.add(10);
        arr.add(20);
        arr.add(30);
        std::cout << "DynamicArray:" << std::endl;
        std::cout << arr << std::endl;
    }catch(const std::bad_alloc& e){
        std::cout << "Memory allocation error" << e.what() << std::endl;
    }catch(const std::out_of_range& e){
        std::cout << "out of range error" << e.what() << std::endl;
    }catch(const std::exception& e){
        std::cout << "exception error" << e.what() << std::endl;
    }
    try{
        MemoryPool pool(sizeof(Student), 3);
        void *meme1 = pool.allocate();
        void *meme2 = pool.allocate();
        void *meme3 = pool.allocate();
        Student *obj1 = new(meme1) Student("Tom", 20);
        Student *obj2 = new(meme2) Student("Jack1", 18);
        Student *obj3 = new(meme3) Student("Jack2", 18);
        
        std::cout << "obj1 name is:" << (*obj1).GetName() << ",age is:" << (*obj1).GetAge() << std::endl;
        std::cout << "obj2 name is:" << obj2->GetName() << ",age is:" << obj2->GetAge() << std::endl;
        std::cout << "obj3 name is:" << obj2->GetName() << ",age is:" << obj3->GetAge() << std::endl;
        void *meme4 = pool.allocate();
        Student *obj4 = new(meme4) Student("Jack3", 18);
        
        obj1->~Student();
        obj2->~Student();
        obj3->~Student();

        pool.deallocate(meme1);
        pool.deallocate(meme2);
        pool.deallocate(meme3);
        obj4->~Student();
        pool.deallocate(meme4);
    }catch(const std::bad_alloc& e){
        std::cout << "Memory allocation error" << e.what() << std::endl;
        return 1; 
    }

    return 0;
}