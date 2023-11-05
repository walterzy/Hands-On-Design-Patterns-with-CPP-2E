#include <iostream>

template <typename ... T> struct Group;
template <typename T1> struct Group<T1> {
    T1 t1_;
    Group() = default;
    explicit Group(const T1& t1) : t1_(t1) {}
    explicit Group(T1&& t1) : t1_(std::move(t1)) {}
    explicit operator const T1&() const { return t1_; }
    explicit operator T1&() { return t1_; }
};
template <typename T1, typename ... T>
struct Group<T1, T ...> : Group<T ...> {
    T1 t1_;
    Group() = default;
    explicit Group(const T1& t1, T&& ... t) : Group<T ...>(std::forward<T>(t) ...), t1_(t1) {}
    explicit Group(T1&& t1, T&& ... t) : Group<T...>(std::forward<T>(t)...), t1_(std::move(t1)) {}
    explicit operator const T1&() const { return t1_; }
    explicit operator T1&() { return t1_; }
};

/*
explicit operator const T1&() const { return t1_; }
operator const T1&() const 表示这是一个类型转换操作符，它会将 MyClass 转换为 T1 类型的常量左值引用
（const T1&）。最后的 const 关键字表示这个操作符是一个常量成员函数，因此它可以被调用在 const 对象上。

explicit operator T1&() { return t1_; }
这里定义了一个显式类型转换操作符（explicit conversion operator），用于将一个类（假设类的名称为 MyClass）
转换为 T1 类型的左值引用。这意味着，当你试图将一个 MyClass 对象转换为 T1 类型时，
编译器将使用这个显式类型转换操作符来执行转换。
*/

template <typename ... T> Group(T&&... t) -> Group<T...>;
/*
它定义了一个模板类 Group，该模板类接受一个参数包 T，并使用尾随返回类型（trailing return type）
指定了模板类自身的类型。这实际上是模板别名的一种应用，用于简化模板的定义。
*/

template <typename ... T> auto makeGroup(T&& ... t) { return Group<T ...>(std::forward<T>(t) ...); }

int main() {
    Group<int, long> g1(1, 2);
    std::cout << int(g1) << std::endl;
    Group g2(3, 2.2, std::string("xyz"));
    std::cout << int(g2) << std::endl;
    std::cout << double(g2) << std::endl;
    std::cout << std::string(g2) << std::endl;
    auto g3 = makeGroup(3, 2.2, std::string("xyz"));
    std::cout << int(g3) << std::endl;
    std::cout << double(g3) << std::endl;
    std::cout << std::string(g3) << std::endl;
}
