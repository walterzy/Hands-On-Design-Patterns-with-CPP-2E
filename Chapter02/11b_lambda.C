#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::vector<double> v { 1, 2.001, 10, 8, 6, 2, 4 };
    double tolerance = 0.01;
    size_t count = 0;
    auto compare_with_tolerance = [=, &count](auto x, auto y) mutable {
        std::cout << "called " << ++count << " times\n";
        return x < y && std::abs(x - y) > tolerance;
    };
    std::sort(v.begin(), v.end(), compare_with_tolerance);

    for (auto x: v) std::cout << x << " ";
    std::cout << "\nlambda called " << count << " times\n";
}
