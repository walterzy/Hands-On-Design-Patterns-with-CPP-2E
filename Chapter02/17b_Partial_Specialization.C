#include <iostream>

template <typename T> class Value; // Declaration

template <typename T> class Value<T*> {
public:
    explicit Value(T* p) : v_(*p) {} 

private:
    T v_;
};

template <typename T> class Value<T&> {
public:
    explicit Value(T& p) : v_(p) {}

private:
    T v_;
};

int main()
{
    int i = 5; int* p = &i; int& r = i;
    Value<int*> v1(p); // T* specialization
    Value<int&> v2(r); // T& specialization
}
