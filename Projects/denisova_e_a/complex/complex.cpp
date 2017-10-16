#include <iostream>
#include <sstream>
#include "complex.h"


Complex::Complex(const double real)
	: Complex(real, 0.0)
{}

Complex::Complex(const double real, const double imaginary)
	: re(real)
	, im(imaginary)
{
}

bool Complex::operator==(const Complex& rhs)
{
	double eps = 0.00001;
	if ((abs(re - rhs.re) < eps) && (abs(im - rhs.im) < eps))
		return true;
	else
		return false;
}


Complex operator+(const Complex& rhs, const Complex& lhs)
{
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex operator+(const Complex& rhs, const double lhs)
{
	return (rhs + Complex(lhs));
}

Complex operator+(const double rhs, const Complex& lhs)
{
	return (Complex(rhs) + lhs);
}

Complex& Complex:: operator+=(const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex operator-(const Complex& rhs, const Complex& lhs)
{
	Complex dif(rhs);
	dif -= lhs;
	return dif;
}

Complex operator-(const Complex& rhs, const double lhs)
{
	return (rhs - Complex(lhs));
}

Complex operator-(const double rhs, const Complex& lhs)
{
	return (Complex(rhs) - lhs);
}

Complex& Complex::operator-=(const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
	return Complex(rhs.re*lhs.re - rhs.im*lhs.im, lhs.re*rhs.im + lhs.im*rhs.re);
}

Complex operator*(const Complex& rhs, const double lhs)
{
	Complex rez(rhs);
	rez *= lhs;
	return rez;
}

Complex operator*(const double rhs, const Complex& lhs)
{
	Complex rez(lhs);
	rez *= rhs;
	return rez;
}

Complex& Complex::operator*=(const double rhs)
{
	re *= rhs;
	im *= rhs;
	return *this;
}

Complex& Complex::operator*=(const Complex& rhs)
{
	Complex z;
	z.re = re*rhs.re - im*rhs.im;
	z.im = re*rhs.im + im*rhs.re;
	*this = z;
	return *this;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
	return Complex((rhs.re*lhs.re + rhs.im*lhs.im) / (rhs.re*rhs.re + rhs.im*rhs.im), (rhs.re*lhs.im - rhs.im*lhs.re) / (rhs.re*rhs.re + rhs.im*rhs.im));
}

Complex operator/(const Complex& rhs, const double lhs)
{
	Complex llhs(lhs);
	Complex rez = rhs / llhs;
	return rez;
}

Complex operator/(const double rhs, const Complex& lhs)
{
	Complex rez(rhs);
	rez /= lhs;
	return rez;
}

Complex& Complex::operator/=(const double rhs)
{
	re /= rhs;
	im /= rhs;
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs)
{
	Complex z;
	z.re = (re*rhs.re + im*rhs.im) / (rhs.re*rhs.re + rhs.im*rhs.im);
	z.im = (im*rhs.re - rhs.im*re) / (rhs.re*rhs.re + rhs.im*rhs.im);
	*this = z;
	return *this;
}

Complex& Complex::operator++()
{
	*this += Complex(1);
	return *this;
}

Complex Complex::operator++(int)
{
	Complex initvalue(*this);
	++(*this);
	return initvalue;
}

Complex& Complex::operator--()
{
	*this -= Complex(1);
	return *this;
}

Complex Complex::operator--(int)
{
	Complex initvalue(*this);
	--(*this);
	return initvalue;
}
std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	ostrm << leftbrace << re << separator << im << rightbrace;
	return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
	char leftbrace(0);
	double real(0);
	char comma(0);
	double imaginary(0.0);
	char rightbrace(0);
	istrm >> leftbrace >> real >> comma >> imaginary >> rightbrace;
	if (istrm.good()) {
		if ((Complex::leftbrace == leftbrace) && (Complex::separator == comma) && (Complex::rightbrace == rightbrace)){
			re = real;
			im = imaginary;
		}
		else{
			istrm.setstate(std::ios_base::failbit);
		}
		return istrm;
	}
}