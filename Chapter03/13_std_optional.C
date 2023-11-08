#include <iostream>
#include <optional>

/*
std::optional 是C++17引入的标准库类型，它提供了一种表示可选值的方式。它的目的是解决在某些情况下，
你可能需要一个值，但这个值可能不存在（空）。你可以将std::optional视为一种容器，
可以包含一个值或不包含任何值。

下面是一些关于std::optional的基本理解：

    表示可选值：std::optional可以用来表示一个可能存在或可能不存在的值。
        这对于函数返回值、配置选项和其他情况非常有用，因为你可以清楚地表达“有值”和“无值”的情况。

    避免空指针：与使用裸指针不同，std::optional不会导致空指针异常。你可以安全地访问std::optional的值，
        而无需担心空指针引用。

    使用方式：你可以通过std::optional的std::nullopt来表示没有值，
        或者通过std::optional的构造函数将值包装到std::optional中。
        然后，你可以使用条件语句（如if语句）来检查std::optional是否包含值，以及如何访问这个值。
*/

int main() {
    std::optional<int> maybeValue;  // 创建一个空的std::optional

    if (maybeValue.has_value()) {
        std::cout << "has value:" << maybeValue.value() << std::endl;
    } else {
        std::cout << "No Value" << std::endl;
    }

    maybeValue = 42;  // 将值包装到std::optional中

    if (maybeValue.has_value()) {
        std::cout << "has value:" << maybeValue.value() << std::endl;
    } else {
        std::cout << "No Value" << std::endl;
    }

    return 0;
}
