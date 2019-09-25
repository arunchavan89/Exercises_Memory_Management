#include <iostream>
#include <memory> //unique_ptr

class MyClass{
public:
    void class_method()
    {
        std::cout << "MyClass::class_method()" << std::endl;
    }
};

int main()
{
    //define a shared_ptr
    std::shared_ptr<MyClass>shared_ptr_1(new MyClass);
    shared_ptr_1->class_method();

    //print memory address of ptr_1
    std::cout << shared_ptr_1.get() << std::endl;
    //count how many shared pointers are associated with the same memory
    std::cout << shared_ptr_1.use_count() << std::endl;

    //share memory 
    std::shared_ptr<MyClass>shared_ptr_2(shared_ptr_1);
    //at this point two pointers are associated with the same memory
    std::cout << shared_ptr_1.use_count() << std::endl;
    std::cout << shared_ptr_2.use_count() << std::endl;

    //delete memory of shared_ptr_1
    shared_ptr_1.reset();
    //at this point one pointers are associated with the same memory
    std::cout << shared_ptr_1.use_count() << std::endl;  //zero
    std::cout << shared_ptr_2.use_count() << std::endl;  //one

    getchar();
    return 0;
}