#include <iostream>
#include <vector>

/*
std::move 是 C++ 标准库中的一个函数模板，用于将对象的所有权从一个对象转移到另一个对象，
通常用于支持移动语义。它实际上并不移动对象的数据，而是将对象的状态标记为"右值"，
这意味着它可以被有效地移动，而不是复制。std::move通常用于优化对象的复制操作，
特别是在使用 C++11 引入的移动语义时。

以下是一些关于std::move的重要概念：

    移动语义：移动语义是 C++11 引入的一项特性，允许将资源（例如内存、文件句柄等）从一个对象
        转移到另一个对象，而不是复制资源。这提高了性能，特别是对于大型数据结构。
        std::move用于启用移动语义。

    标记对象为右值：std::move将对象标记为右值引用，这表示编译器可以将其数据有效地移动而不复制。
        这通常通过将左值引用转换为右值引用来实现，使对象的所有权可以传递给另一个对象。

    不进行实际移动：std::move本身并不执行实际的数据移动，它只是改变了对象的状态，以允许移动操作的发生。
        移动操作通常是由类的移动构造函数或移动赋值运算符实现的。
*/

int main() {
    std::vector<int> source = {1, 2, 3};
    std::vector<int> destination;

    destination = std::move(source);  // 使用 std::move 将 source 移动到 destination

    std::cout << "Source size: " << source.size() << std::endl;  // 此时 source 对象为空
    std::cout << "Destination size: " << destination.size() << std::endl;  // destination 包含源数据

    return 0;
}

