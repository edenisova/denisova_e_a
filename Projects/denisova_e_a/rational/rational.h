#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <iosfwd>

struct Rational{
	Rational() = default;
	~Rational() = default;
	explicit Rational(const int numerator);
	Rational(const int numerator, const int denuminator);
	bool operator==(const Rational& rhs) const{ return (num == rhs.num) && (denum == rhs.denum); }
	bool operator!=(const Rational& rhs) const{ return !operator==(rhs); }
	bool operator>(const Rational& rhs);
	bool operator>=(const Rational& rhs);
	bool operator<(const Rational& rhs);
	bool operator<=(const Rational& rhs);
	Rational& operator+=(const int rhs);
	Rational& operator+=(const Rational& rhs);
	Rational& operator-=(const int rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator*=(const int rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator/=(const int rhs);
	Rational& operator/=(const Rational& rhs);
	Rational& operator=(const Rational& rhs) = default;
	Rational& operator++();
	Rational operator++(int);
	Rational& operator--();
	Rational operator--(int);
    static void bcd(int& num, int& denum);
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);
	int num;
	int denum;

	static const char separator{ '/' };
};

Rational operator+(const Rational& rhs, const Rational& lhs);
Rational operator+(const Rational& rhs, const int lhs);
Rational operator+(const int rhs, const Rational& lhs);
Rational operator-(const Rational& rhs, const Rational& lhs);
Rational operator-(const Rational& rhs, const int lhs);
Rational operator-(const int rhs, const Rational& lhs);
Rational operator*(const Rational& rhs, const Rational& lhs);
Rational operator*(const Rational& rhs, const int lhs);
Rational operator*(const int rhs, const Rational& lhs);
Rational operator/(const Rational& rhs, const Rational& lhs);
Rational operator/(const Rational& rhs, const int lhs);
Rational operator/(const int rhs, const Rational& lhs);


inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}
#endif