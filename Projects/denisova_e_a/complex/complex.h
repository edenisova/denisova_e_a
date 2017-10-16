#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <iosfwd>

struct Complex
{
	Complex() = default;
	~Complex() = default;
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);
	bool operator==(const Complex& rhs);
	bool operator!=(const Complex& rhs) { return !operator==(rhs); }
	Complex& operator +=(const Complex& rhs);
	Complex& operator+=(const double rhs) { return operator +=(Complex(rhs)); }
	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double rhs);
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
	Complex& operator/=(const double rhs);
	Complex& operator/=(const Complex& rhs);
	Complex& operator=(const Complex& rhs) = default;
	Complex& operator++();
	Complex operator++(int);
	Complex& operator--();
	Complex operator--(int);
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftbrace{ '{' };
	static const char separator{ ',' };
	static const char rightbrace{ '}' };
};
Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& rhs, const double lhs);
Complex operator+(const double rhs, const Complex& lhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& rhs, const double lhs);
Complex operator-(const double rhs, const Complex& lhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& rhs, const double lhs);
Complex operator*(const double rhs, const Complex& lhs);
Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& rhs, const double lhs);
Complex operator/(const double rhs, const Complex& lhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
	return rhs.readFrom(istrm);
}
#endif