#include <iostream>
#include <sstream>
#include "rational.h"
#include <cmath>

void Rational::bcd(int& num, int& denum)
{
	int numc = abs(num);
	int denumc = denum;
	while ((numc != 0) && (denumc != 0))
		if (numc > denumc)
			numc = numc%denumc;
		else
			denumc = denumc%numc;
	if ((numc + denumc) != 0)
	{
		num /= (numc + denumc);
		denum /= (numc + denumc);
	}
}

Rational::Rational(const int numerator): Rational(numerator, 1)
{
}

Rational::Rational(const int numerator, const int denumerator): num(numerator), denum(denumerator)
{
	if (denum < 0)
	{
		num = -num;
		denum = abs(denum);
	}
	bcd(num, denum);
}

bool Rational::operator>(const Rational& rhs)
{
	double eps = 0.00001;
	if ((double)num / denum - (double)rhs.num / rhs.denum > eps)
	{
		return true;
	}
	else 
		return false;
}

bool Rational::operator>=(const Rational& rhs)
{
	double eps = 0.00001;
	if ((double)num / denum - (double)rhs.num / rhs.denum > -eps)
	{
		return true;
	}
	else
		return false;
}

bool Rational::operator<(const Rational& rhs)
{
	double eps = 0.00001;
	if ((double)num / denum - (double)rhs.num / rhs.denum < -eps)
	{
		return true;
	}
	else
		return false;
}

bool Rational::operator<=(const Rational& rhs)
{
	double eps = 0.00001;
	if ((double)num / denum - (double)rhs.num / rhs.denum < eps)
	{
		return true;
	}
	else
		return false;
}

Rational operator+(const Rational& rhs, const Rational& lhs)
{
	Rational sum;
	if (rhs.denum == lhs.denum)
	{
		sum.num = rhs.num + lhs.num;
		sum.denum = rhs.denum;
	}
	else
	{
		sum.denum = rhs.denum*lhs.denum;
		sum.num = rhs.num*lhs.denum + rhs.denum*lhs.num;
	}
	Rational::bcd(sum.num, sum.denum);
	return sum;
}

Rational operator+(const Rational& rhs, const int lhs)
{
	return Rational(rhs.num + lhs*rhs.denum, rhs.denum);
}

Rational operator+(const int rhs, const Rational& lhs)
{
	return Rational(lhs.num + rhs*lhs.denum, lhs.denum);
}

Rational operator-(const Rational& rhs, const Rational& lhs)
{
	Rational diff;
	if (rhs.denum == lhs.denum)
	{
		diff.num = rhs.num - lhs.num;
		diff.denum = rhs.denum;
	}
	else
	{
		diff.denum = rhs.denum*lhs.denum;
		diff.num = rhs.num*lhs.denum - rhs.denum*lhs.num;
	}
	Rational::bcd(diff.num, diff.denum);
	return diff;
}

Rational operator-(const Rational& rhs, const int lhs)
{
	return Rational(rhs.num-lhs*rhs.denum, rhs.denum);
}

Rational operator-(const int rhs, const Rational& lhs)
{
	return Rational(lhs.num - rhs*lhs.denum, lhs.denum);
}

Rational operator*(const Rational& rhs, const Rational& lhs)
{
	return Rational(rhs.num*lhs.num, rhs.denum*lhs.denum);
}

Rational operator*(const Rational& rhs, const int lhs)
{
	return Rational(rhs.num*lhs, rhs.denum);
}

Rational operator*(const int rhs, const Rational& lhs)
{
	return Rational(lhs.num*rhs, lhs.denum);
}

Rational operator/(const Rational& rhs, const Rational& lhs)
{
	return Rational(rhs.num*lhs.denum, rhs.denum*lhs.num);
}

Rational operator/(const Rational& rhs, const int lhs)
{
	return Rational(rhs.num, rhs.denum*lhs);
}

Rational operator/(const int rhs, const Rational& lhs)
{
	return Rational(lhs.num, lhs.denum*rhs);
}

Rational& Rational::operator+=(const int rhs)
{
	num += rhs*denum;
	bcd(num, denum);
	return *this;
}

Rational& Rational::operator+=(const Rational& rhs)
{
	num = num*rhs.denum + rhs.num*denum;
	denum *= rhs.denum;
	bcd(num, denum);
	return *this;
}

Rational& Rational::operator-=(const int rhs)
{
	num -= rhs*denum;
	bcd(num, denum);
	return *this;
}

Rational& Rational::operator-=(const Rational& rhs)
{
	if (denum == rhs.denum)
	{
		num -= rhs.num;
	}
	else 
	{
		num = num*rhs.denum - rhs.num*denum;
		denum *= rhs.denum;
	}
	bcd(num, denum);
	return *this;
}

Rational& Rational::operator*=(const int rhs)
{
	num *= rhs;
	bcd(num, denum);
	return *this;
}

Rational& Rational::operator*=(const Rational& rhs)
{
	num *= rhs.num;
	denum *= rhs.denum;
	bcd(num, denum);
	return *this;
}

Rational& Rational::operator/=(const int rhs)
{
	denum *= rhs;
	bcd(num, denum);
	return *this;
}

Rational& Rational::operator/=(const Rational& rhs)
{
	num *= rhs.denum;
	denum *= rhs.num;
	bcd(num, denum);
	return *this;
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
	ostrm << num << separator << denum;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
	int numerator(0);
	char slash(0);
	int denumerator(0);
	istrm >> numerator >> slash >> denumerator;
	if (istrm.good()) {
		if ((Rational::separator == slash)){
			num = numerator;
			denum = denumerator;
		}
		else{
			istrm.setstate(std::ios_base::failbit);
		}
		return istrm;
	}
}