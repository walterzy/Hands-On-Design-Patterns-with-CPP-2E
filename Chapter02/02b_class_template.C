#include <iostream>

template <typename N, typename D> class Ratio {
public:
    Ratio() : num_(), denom_() {}
    Ratio(const N& num, const D& denom) :
        num_(num), denom_(denom) {}
    explicit operator double() const {
        return double(num_)/double(denom_);
    }

private:
    N num_;
    D denom_;
};

template <typename N, typename D>
Ratio<N, D> make_ratio(const N& num, const D& denom) {
    return { num, denom };
}

int main()
{
    Ratio<int, double> r;
    Ratio r1(5, 0.1);
    auto r2(make_ratio(5, 0.1));
}

