#include <iostream>

class Fraction
{
private:
	int numerator = 0;
	int denominator = 0;

public:
	Fraction(int numerator_, int denominator_)
	{
		numerator = numerator_;
		denominator = denominator_;
	}
	bool operator< (Fraction f) {
		if (denominator == f.denominator) {
			return (numerator < f.numerator ? 1 : 0);
		}
		else {
			return ((numerator * f.denominator) < (f.numerator * denominator) ? 1 : 0);
		}
	}
	bool operator> (Fraction f) {
		if (denominator == f.denominator) {
			return (numerator > f.numerator ? 1 : 0);
		}
		else {
			return ((numerator * f.denominator) > (f.numerator * denominator) ? 1 : 0);
		}
	}
	bool operator<= (Fraction f) {
		if (denominator == f.denominator) {
			return (numerator <= f.numerator ? 1 : 0);
		}
		else {
			return ((numerator * f.denominator) <= (f.numerator * denominator) ? 1 : 0);
		}
	}
	bool operator>= (Fraction f) {
		if (denominator == f.denominator) {
			return (numerator >= f.numerator ? 1 : 0);
		}
		else {
			return ((numerator * f.denominator) >= (f.numerator * denominator) ? 1 : 0);
		}
	}
	bool operator== (Fraction f) {
		if (denominator == f.denominator) {
			return (numerator == f.numerator ? 1 : 0);
		}
		else {
			return ((numerator * f.denominator) == (f.numerator * denominator) ? 1 : 0);
		}
	}
		bool operator!= (Fraction f) {
			if (denominator == f.denominator) {
				return (numerator != f.numerator ? 1 : 0);
			}
			else {
				return ((numerator * f.denominator) != (f.numerator * denominator) ? 1 : 0);
			}
		}
};

int main () {
	Fraction f1(4, 8); //4, 3
	Fraction f2(2, 1); //6, 11

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}