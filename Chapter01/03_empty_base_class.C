#include <iostream>

// 创建一个空的基类
class EmptyBaseClass {};

// 创建一个派生类，不包含任何额外成员
class DerivedClass : public EmptyBaseClass {};

class Empty {
public:
    void useful_function();
};

class Derived : private Empty {
    int i;
}; // sizeof(Derived) == 4

class Composed {
    int i;
    Empty e;
}; // sizeof(Composed) == 8

int main() {
    std::cout << "Size of EmptyBaseClass: " << sizeof(EmptyBaseClass) << " bytes" << std::endl;
    std::cout << "Size of DerivedClass: " << sizeof(DerivedClass) << " bytes" << std::endl;

    std::cout << "Size of Empty: " << sizeof(Empty) << " bytes" << std::endl;
    std::cout << "Size of Derived: " << sizeof(Derived) << " bytes" << std::endl;
    std::cout << "Size of Composed: " << sizeof(Composed) << " bytes" << std::endl;

    return 0;
}
