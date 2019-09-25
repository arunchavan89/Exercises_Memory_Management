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
    //define unique ptr
    std::unique_ptr<MyClass>ptr_1(new MyClass);
    ptr_1->class_method();

    //print address of unique ptr
    std::cout << ptr_1.get() << std::endl;

    //move address of ptr_1 to ptr_2
    std::unique_ptr<MyClass>ptr_2 = move(ptr_1);
    ptr_2->class_method();
    std::cout << ptr_1.get() << std::endl;
    std::cout << ptr_2.get() << std::endl;
    
    //move address of ptr_2 to ptr_3
    std::unique_ptr<MyClass>ptr_3 = move(ptr_2);
    ptr_3->class_method();
    std::cout << ptr_1.get() << std::endl;
    std::cout << ptr_2.get() << std::endl;
    std::cout << ptr_3.get() << std::endl;

    getchar();
    return 0;
}