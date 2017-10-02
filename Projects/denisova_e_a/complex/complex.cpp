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
	return Complex(rhs.re + lhs, rhs.im);
}

Complex operator+(const double rhs, const Complex& lhs)
{
	return Complex(lhs.re + rhs, lhs.im);
}

Complex& Complex:: operator+=(const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex operator-(const Complex& rhs, const Complex& lhs)
{
	return Complex(rhs.re - lhs.re, rhs.im - lhs.im);
}

Complex operator-(const Complex& rhs, const double lhs)
{
	return Complex(rhs.re - lhs, rhs.im);
}

Complex operator-(const double rhs, const Complex& lhs)
{
	return Complex(rhs - lhs.re, -lhs.im);
}

Complex& Complex::operator-=(const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
	return Complex(rhs.re*lhs.re - rhs.im*lhs.im, rhs.re*lhs.im + rhs.im + lhs.re);
}

Complex operator*(const Complex& rhs, const double lhs)
{
	return Complex(rhs.re*lhs, rhs.im*lhs);
}

Complex operator*(const double rhs, const Complex& lhs)
{
	return Complex(lhs.re*rhs, lhs.im*rhs);
}

Complex& Complex::operator*=(const double rhs)
{
	re *= rhs;
	im *= rhs;
	return *this;
}

Complex& Complex::operator*=(const Complex& rhs)
{
	re = re*rhs.re - im*rhs.im;
	im = re*rhs.im + im + rhs.re;
	return *this;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
	return Complex((rhs.re*lhs.re + rhs.im*lhs.im) / (rhs.re*rhs.re + rhs.im*rhs.im), (rhs.re*lhs.im - rhs.im*lhs.re) / (rhs.re*rhs.re + rhs.im*rhs.im));
}

Complex operator/(const Complex& rhs, const double lhs)
{
	return Complex(rhs.re / lhs, rhs.im / lhs);
}

Complex operator/(const double rhs, const Complex& lhs)
{
	Complex rrhs(rhs);
	return Complex((lhs.re*rrhs.re + lhs.im*rrhs.im) / (lhs.re*lhs.re + lhs.im*lhs.im), (lhs.re*rrhs.im - lhs.im*rrhs.re) / (lhs.re*lhs.re + lhs.im*lhs.im));
}

Complex& Complex::operator/=(const double rhs)
{
	re /= rhs;
	im /= rhs;
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs)
{
	re = (re*rhs.re + im*rhs.im) / (rhs.re*rhs.re + rhs.im*rhs.im);
	im = (im*rhs.re - rhs.im*re) / (rhs.re*rhs.re + rhs.im*rhs.im);
	return *this;
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