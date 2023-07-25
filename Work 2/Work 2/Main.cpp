#include <iostream>
#include <string>


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
	std::string show() {
		return std::to_string(numerator_) + '/' + std::to_string(denominator_);
	}
	void reduction(int& num, int& denom, int& nul, bool& sigh) {
		int n;
		nul = 2;
		if (num < 0 || denom < 0) {
			sigh = 0;
		}
		else {
			sigh = 1;
		}
		if (num == 0) {
			nul = 0;
			return;
		}
		if (abs(num) < abs(denom)) {
			n = abs(num);
		}
		else if (abs(num) > abs(denom)) {
			n = abs(denom);
		}
		else {
			if (abs(num) == abs(denom)) {

				nul = 1;
				return;
			}
		}
		for (int i = n; i > 0; --i) {
			if (num % i == 0 && denom % i == 0) {
				num = num / i;
				denom = denom / i;
				return;
			}
		}
		
	}
	std::string show_alone(int num, int denom, int nul, bool sigh) {
		if (nul == 0) {
			return "0";
		}
		else if (nul == 1) {
			if (sigh == 1) {
				return "1";
			}
			else {
				return "-1";
			}
		}
		else if (nul == 2) {
			if (sigh == 1) {
				return std::to_string(num) + '/' + std::to_string(denom);
			}
			else {
				return std::to_string(num) + '/' + std::to_string(denom);
			}
		}

	}

	std::string operator+ (Fraction f) {
		int num, denom, nul;
		bool sigh = 1;
		denom = denominator_ * f.denominator_;
		num = (numerator_ * f.denominator_) + (f.numerator_ * denominator_);
		reduction (num, denom, nul, sigh);
		return show_alone (num, denom, nul, sigh);
	}
	std::string operator- (Fraction f) {
		int num, denom, nul;
		bool sigh;
		denom = denominator_ * f.denominator_;
		num = (numerator_ * f.denominator_) - (f.numerator_ * denominator_);
		reduction(num, denom, nul, sigh);
		return show_alone(num, denom, nul, sigh);
	}
	std::string operator* (Fraction f) {
		int num, denom, nul;
		bool sigh;
		denom = denominator_ * f.denominator_;
		num = numerator_ * f.numerator_;
		reduction(num, denom, nul, sigh);
		return show_alone(num, denom, nul, sigh);
	}
	std::string operator/ (Fraction f) {
		int num, denom, nul;
		bool sigh;
		denom = denominator_ * f.numerator_;
		num = numerator_ * f.denominator_;
		reduction(num, denom, nul, sigh);
		return show_alone(num, denom, nul, sigh);
	}
	Fraction operator++ () {
		numerator_ += denominator_;
		return *this;
	}
	Fraction operator-- (int) {
		int temp = numerator_;
		numerator_ -= denominator_;
		return Fraction (temp, denominator_);
	}
};



int main()
{
	setlocale(LC_ALL, "rus");
	int n1, d1, n2, d2;
	try {
		std::cout << "Введите числитель дроби 1: ";
		std::cin >> n1;
		if (n1 == 0) throw (std::invalid_argument("Значение операнда \"0\""));
		std::cout << "Введите знаменатель дроби 1: ";
		std::cin >> d1; 
		if (n1 == 0) throw (std::invalid_argument("Значение операнда \"0\""));
		std::cout << "Введите числитель дроби 2: ";
		std::cin >> n2; 
		if (n1 == 0) throw (std::invalid_argument("Значение операнда \"0\""));
		std::cout << "Введите знаменатель дроби 2: ";
		std::cin >> d2; 
		if (n1 == 0) throw (std::invalid_argument("Значение операнда \"0\""));
	}
	catch (const std::invalid_argument& er) {
		std::cout << er.what();
	}
	Fraction f1(n1, d1);
	Fraction f2(n2, d2);
	
	std::cout << f1.show() << " + " << f2.show() << " = " << f1 + f2 << std::endl;
	std::cout << f1.show() << " - " << f2.show() << " = " << f1 - f2 << std::endl;
	std::cout << f1.show() << " * " << f2.show() << " = " << f1 * f2 << std::endl;
	std::cout << f1.show() << " / " << f2.show() << " = " << f1 / f2 << std::endl;
	std::cout << "++" << f1.show() << " * " << f2.show() << " = " << ++f1 * f2 << std::endl;
	std::cout << "Значение дроби 1: " << f1.show() << std::endl;
	std::cout << f1.show() << "--" << " * " << f2.show() << " = " << f1-- * f2 << std::endl;
	std::cout << "Значение дроби 1: " << f1.show() << std::endl;
	return 0;
}