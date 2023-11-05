// 'std::forward' 是C++11及以后标准中引入的一个重要函数模板，
// 位于 <utility> 头文件中，主要用于实现完美转发（perfect forwarding）。
// 它的作用是将参数保持其原始的左值或右值特性，并传递给其他函数，通常用于泛型编程和模板元编程中。

// 在C++中，有两个主要的引用限定符：左值引用（&）和右值引用（&&）。对于模板编程，
// 有时候我们需要在不改变参数的引用类型的情况下将参数传递给其他函数。这就是 std::forward 的作用，
// 确保参数被正确传递，不管它是左值还是右值。

#include <iostream>
#include <utility>

void foo(int& x) {
    std::cout << "Lvalue reference: " << x << std::endl;
}

void foo(int&& x) {
    std::cout << "Rvalue reference: " << x << std::endl;
}

template <typename T>
void process(T&& value) {
    // Use std::forward to forward the parameter
    // with the correct reference type (lvalue or rvalue)
    foo(std::forward<T>(value));
}

int main() {
    int x = 42;
    process(x);      // Calls foo with an lvalue reference
    process(123);    // Calls foo with an rvalue reference

    return 0;
}

/*
在上面的代码中，T&& 中的两个 && 表示通用引用（universal reference），它是C++11引入的特性，
用于实现完美转发（perfect forwarding）。通用引用可以接受左值和右值参数，
并将它们以原始的引用类型传递给其他函数。这是通过引用折叠规则实现的。

具体来说，T&& 的含义是：

    当 T 被推导为一个左值类型（例如 int&），T&& 变成左值引用（int& &&，根据引用折叠规则变成 int&）。
    当 T 被推导为一个右值类型（例如 int），T&& 变成右值引用（int&&）。

这使得 T&& 成为一个既能接受左值又能接受右值的通用引用。这就是为什么 T&& 被用于模板函数中，
以便在不改变参数的引用类型的情况下，将参数正确传递给其他函数，实现完美转发。

总之，T&& 作为通用引用，可以接受左值和右值，并根据参数的原始引用类型进行正确的传递，
这是C++中实现完美转发的关键。
*/

/*
C++中的引用折叠规则是一组规则，用于描述在特定情况下如何处理和合并引用类型。
这些规则在泛型编程和模板元编程中至关重要，尤其是涉及通用引用（universal references）
和模板参数的引用类型时。

引用折叠规则的核心概念是，当引用类型相互交互或合并时，编译器如何处理它们，以便生成有效的引用类型。
引用折叠规则包括以下几个方面：

    左值引用和左值引用的合并（Lvalue Reference Collapsing）：
        当两个左值引用（T&）合并时，结果还是一个左值引用。
        例如，T& & 合并后仍然是 T&。

    左值引用和右值引用的合并（Lvalue Reference and Rvalue Reference Collapsing）：
        当一个左值引用和一个右值引用（T& 和 T&&）合并时，结果是一个左值引用。
        例如，T& && 合并后是 T&。

    右值引用和右值引用的合并（Rvalue Reference Collapsing）：
        当两个右值引用（T&&）合并时，结果还是一个右值引用。
        例如，T&& && 合并后仍然是 T&&。

引用折叠规则的应用通常发生在泛型编程的上下文中，特别是当使用通用引用（T&&）来处理不同类型的参数时。
这些规则确保在参数传递或类型推断时，引用类型能够按照一种合理的方式进行合并和处理，
以防止类型歧义和错误的引用折叠。

引用折叠规则是C++语言的一部分，它有助于实现通用代码，确保在各种情况下正确处理不同类型的引用。
这对于模板元编程和STL中的各种容器和算法非常重要。
*/