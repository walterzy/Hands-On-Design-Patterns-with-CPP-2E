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


template <typename D> class Ratio<double, D> {
public:
    Ratio() : value_() {}
    Ratio(const double& num, const D& denom) :
        value_(num/double(denom)) {}
    explicit operator double() const { 
        std::cout.precision(8);
        std::cout << "partial template operator double = " << value_ << std::endl;
        return value_; 
    }

private:
    double value_;
};


template <typename N> class Ratio<N, double> {
public:
    Ratio() : value_() {}
        Ratio(const N& num, const double& denom) :
            value_(double(num)/denom) {}
    explicit operator double() const { return value_; }

private:
    double value_;
};

// a full specialization
template <> class Ratio<double, double> {
public:
    Ratio() : value_() {}
    template <typename N, typename D>
        Ratio(const N& num, const D& denom) :
            value_(double(num)/double(denom)) {}
    explicit operator double() const { return value_; }

private:
    double value_;
};


int main()
{
    Ratio r1(5.0, 0.3);
    (double)r1;
}

