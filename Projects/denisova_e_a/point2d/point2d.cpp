#include "point2d.h"
#include <iostream>
#include <sstream>

const double eps(0.00001);

point2d::point2d(const double kx_, const double ky_) : kx(kx_), ky(ky_){ }

bool point2d::operator==(const point2d& rhs)
{
	return((abs(kx - rhs.kx) < eps) && (abs(ky - rhs.ky) < eps));
}

point2d& point2d::operator+=(const point2d& rhs)
{
	kx += rhs.kx;
	ky += rhs.ky;
	return *this;
}

point2d operator+(const point2d& rhs, const point2d& lhs)
{
	point2d sum(rhs);
	sum += lhs;
	return(sum);
}

point2d& point2d::operator-=(const point2d& rhs)
{
	kx -= rhs.kx;
	ky -= rhs.ky;
	return *this;
}

point2d operator-(const point2d& rhs, const point2d& lhs)
{
	point2d sum(rhs);
	sum += lhs;
	return(sum);
}

point2d operator*(const double rhs, const point2d& lhs)
{
	point2d mult(lhs);
	mult *= rhs;
	return mult;
}

point2d operator*(const point2d& rhs, const double lhs)
{
	point2d mult(rhs);
	mult *= lhs;
	return mult;
}

point2d& point2d::operator*=(const double rhs)
{
	kx *= rhs;
	ky *= rhs;
	return *this;
}

point2d& point2d::operator/=(const double rhs)
{
	kx /= rhs;
	ky /= rhs;
	return *this;
}

point2d operator/(const point2d& rhs, const double lhs)
{
	point2d rez(rhs);
	rez /= lhs;
	return rez;
}

point2d& point2d::changex()
{
	ky = -ky;
	return *this;
}

point2d& point2d::changey()
{
	kx = -kx;
	return *this;
}

std::ostream& point2d::writeTo(std::ostream& ostrm) const
{
	ostrm << kx << separator << ky;
	return ostrm;
}

std::istream& point2d::readFrom(std::istream& istrm)
{
	char separator(0);
	double kx_(0.0);
	double ky_(0.0);
	istrm >> kx >> separator >> ky;
	if (istrm.good())
	{
		if (point2d::separator == separator)
		{
			kx = kx_;
			ky = ky_;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
		return istrm;
	}
}