#include <iostream>

void whatami(int x) { std::cout << x << " is int" << std::endl; }
void whatami(double x) { std::cout << x << " is double" << std::endl; }

template <typename T> void whatami(T* x) {
    std::cout << x << " is a pointer" << std::endl;
}

template <typename T> void whatami(T&&) { 
    std::cout << "Something weird" << std::endl; 
}

void whatami(...) {
    std::cout << "It's something or somethings" << std::endl;
}

int main() {
    int i = 5;
    float x = 4.2;
    whatami(i); // i is int
    whatami(&i); // 0x???? is a pointer
    whatami(x); // Something weird

    class C { };
    C c;
    whatami(c); // Something weird
    whatami(&c); // 0x???? is a pointer
}
