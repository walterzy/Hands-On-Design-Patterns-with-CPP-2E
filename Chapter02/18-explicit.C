// 在现代C++中，explicit 是一个关键字，通常用于声明构造函数。它的主要含义是禁止隐式类型转换，
// 确保只有显式调用才能使用这个构造函数。当一个构造函数被标记为 explicit 时，
// 它将禁止编译器进行隐式类型转换，以防止意外的构造行为发生。
// 这对于防止潜在的错误和提高代码的可读性非常有用。

class MyString {
public:
    MyString(const char* str) {
        // Constructor for creating MyString from a C-style string
    }

    // This constructor is marked as explicit
    explicit MyString(int length) {
        // Constructor for creating MyString with a specified length
    }
};

int main() {
    MyString str1 = "Hello";  // OK, implicit conversion from const char*
    MyString str2(5);         // OK, explicit constructor call

    MyString str3 = 5;        // Error: Implicit conversion from int is not allowed
}
