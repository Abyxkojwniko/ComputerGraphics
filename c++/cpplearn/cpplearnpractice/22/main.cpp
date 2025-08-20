#include <iostream>
#include <thread>
#include "Student.h"
#include "SimpleSharedPtr.h"
#include <memory>

void test_p_int(Student* stu){
    stu->_name = "Ray";

}

int main(){
    // Student* p_student = new Student("Jack", 18);
    // std::cout << *p_student << std::endl;
    // delete p_student;
    // std::thread t1([p_student](){
    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    //     p_student->_name = "Ray";
    // });
    // //delete p_student;
    // test_p_int(p_student);
    // std::cout << *p_student << std::endl;

    // SimpleSharedPtr<Student> ptr1;
    // std::cout << "p_student_count is:" << ptr1.use_count() << std::endl;
    
    // SimpleSharedPtr<Student> ptr2(new Student("zack", 36));
    // std::cout << "p_student_count is:" << ptr2.use_count() << std::endl;
    
    // SimpleSharedPtr<Student> ptr3(ptr2);
    // std::cout << "p_student_count is:" << ptr2.use_count() << std::endl;
    // std::cout << "p_student_count is:" << ptr3.use_count() << std::endl;
    
    // ptr1 = ptr3;
    // std::cout << "p_student_count is:" << ptr1.use_count() << std::endl;
    // std::cout << "p_student_count is:" << ptr2.use_count() << std::endl;
    // std::cout << "p_student_count is:" << ptr3.use_count() << std::endl;
    
    // ptr2.reset(new Student("John", 18));
    // std::cout << "p_student_count is:" << ptr1.use_count() << std::endl;
    // std::cout << "p_student_count is:" << ptr2.use_count() << std::endl;
    // std::cout << "p_student_count is:" << ptr3.use_count() << std::endl;


    // std::thread t1([&ptr2](){
    //     ptr2->_name = "Ray in thread";

    // });
    // t1.join();

    //Student *student = new Student();
    //std::shared_ptr<Student> shared_student(student);
    //std::shared_ptr<Student> shared_student = std::shared_ptr<Student> (student);
    //std::shared_ptr<Student> shared_student(new Student());
    // auto shared_student = std::make_shared<Student>("zack", 35);
    // std::shared_ptr<Student> shared_student2 =  shared_student;
    // std::cout << "After shared_student2 = shared_student, the use count is" << std::endl;
    // std::cout << shared_student2.use_count() << std::endl;
    // std::cout << shared_student.use_count() << std::endl;

    // std::shared_ptr<Student> sp3;
    // sp3 = shared_student2;
    // std::cout << "After shared_student3 = shared_student, the use count is" << std::endl;
    // std::cout << sp3.use_count() << std::endl;

    // shared_student2.reset(new Student("Ray", 23));
    // std::cout << "After shared_student rest, the use count is" << std::endl;
    // std::cout << shared_student2.use_count() << std::endl;
    // std::cout << shared_student.use_count() << std::endl;
    // std::cout << sp3.use_count() << std::endl;


    std::unique_ptr<Student> ptr1(new Student("zack", 23));
    ptr1->print();

    std::unique_ptr<Student> ptr2 = std::move(ptr1);
    //ptr1->print();
    ptr2->print();
    ptr1 = std::unique_ptr<Student> (new Student("Ray", 18));
    ptr1->print();

    std::unique_ptr<Student> ptr3 = std::make_unique<Student>("Vivo", 25);
    ptr3->print();
    
    std::unique_ptr<Student> ptr4 = std::move(ptr3);

    {
        std::shared_ptr<A> a = std::make_shared<A>();
        std::shared_ptr<B> b = std::make_shared<B>();
        a -> ptrB = b;
        b -> ptrA = a;
    }
    return 0;
}