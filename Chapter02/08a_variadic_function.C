// Variadic template function (C++17, fold)
#include <iostream>
#include <type_traits>

/*
C++17引入了折叠表达式（fold expression），它是一种用于在编译时对参数包进行递归操作的新特性。
折叠表达式允许你在编译时展开（fold）参数包的操作，以便在模板编程中更轻松地执行各种操作，
如求和、连接字符串、逻辑操作等
*/

// Base case: This function will print the last parameter.
void printParams() {
    std::cout << std::endl;
}

// Recursive case: This function will print the current parameter and 
// call itself with the remaining parameters.
template <typename T, typename... Args>
void printParams(T first, Args... rest) {
    std::cout << first << " ";
    printParams(rest...);
}

template <typename ... T> auto sum(const T& ... x) { 
    printParams(x...);
    return (x + ...); 
}


int main() {
    std::cout << sum(5, 7, 3) << std::endl;
    static_assert(std::is_same_v<decltype(sum(5, 7, 3)), int>);
    std::cout << sum(5, 7L, 3) << std::endl;
    static_assert(std::is_same_v<decltype(sum(5, 7L, 3)), long>);
    std::cout << sum(5, 7L, 2.9) << std::endl;
    static_assert(std::is_same_v<decltype(sum(5, 7L, 2.9)), double>);
}
