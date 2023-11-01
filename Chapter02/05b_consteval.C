// Example of conteval function (C++20)
#include <iostream>

// consteval - specifies that a function is an immediate function, that is, 
// every call to the function must produce a compile-time constant
consteval size_t length(const char* s) { size_t res = 0; while (*(s++)) ++res; return res; }

int main() {
    std::cout << length("abc") << std::endl;
    static_assert(length("abc") == 3, "");
    char s[] = "runtime"; (void)s;
    //std::cout << length(s) << std::endl; // Not consteval
    //static_assert(length(s) == 7, "");
}
