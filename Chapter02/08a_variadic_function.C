// Variadic template function (C++17, fold)
#include <iostream>
#include <type_traits>

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
