#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	bool operator< (Fraction f) {
		return (numerator_ < f.numerator_ ? 1 : (numerator_ == f.numerator_ ? (denominator_ < f.denominator_ ? 1 : 0) : 0));
	}
	bool operator> (Fraction f) {
		return (numerator_ > f.numerator_ ? 1 : (numerator_ == f.numerator_ ? (denominator_ > f.denominator_ ? 1 : 0) : 0));
	}
	bool operator<= (Fraction f) {
		return (numerator_ <= f.numerator_ ? (numerator_ < f.numerator_ ? 1 : (denominator_ <= f.denominator_ ? 1 : 0)) : 0);
	}
	bool operator>= (Fraction f) {
		return (numerator_ >= f.numerator_ ? (numerator_ > f.numerator_ ? 1 : (denominator_ >= f.denominator_ ? 1 : 0)):0);
	}
	bool operator== (Fraction f) {
		return (numerator_ == f.numerator_ && denominator_ == f.denominator_);
	}
	bool operator!= (Fraction f) {
		return (numerator_ != f.numerator_ || denominator_ != f.denominator_);
	}
#if 0 // В моей версии "spaceship" не поддерживается
	auto operator<=> (const Fraction&) const = default;
#endif
};

int main()
{
	Fraction f1(4, 3); //4, 3
	Fraction f2(6, 11); //6, 11

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}