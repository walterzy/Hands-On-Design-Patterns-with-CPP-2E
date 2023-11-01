#include <iostream>

template <typename N, typename D> class Ratio {
public:
    Ratio() : num_(), denom_() {}
    Ratio(const N& num, const D& denom) :
        num_(num), denom_(denom) {
            std::cout << "general template\n";
        }
    explicit operator double() const {
        std::cout.precision(8);
        std::cout << "general template operator double = " << double(num_)/double(denom_) << std::endl;

        return double(num_)/double(denom_);
    }

private:
    N num_;
    D denom_;
};

template <> class Ratio<double, double> {
public:
    Ratio() : value_() { std::cout << "explicit Specialization constructor\n"; }
    template <typename N, typename D>
        Ratio(const N& num, const D& denom) :
            value_(double(num)/double(denom)) {
                std::cout << "explicit Specialization template\n";
            }
    explicit operator double() const { 
        std::cout.precision(8);
        std::cout << "explicit Specialization operator double = " << value_ << std::endl;
        return value_; 
    }

private:
    double value_;
};

template <> Ratio<float, float>::operator double() const {
    return num_/denom_;
}

int main()
{
    Ratio<int, double> r;
    
    Ratio r1(5, 0.3);
    (double)r1;
    
    Ratio r2(5.0, 0.3);
    (double)r2;
}
