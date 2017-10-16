#include <iostream>
#include <sstream>
#include "vec3d.h"
#include <cmath>

vec3d::vec3d(const double x_, const double y_, const double z_) : x(x_), y(y_), z(z_){ }

bool vec3d::operator==(const vec3d& rhs)
{
	if ((x == rhs.x) && (y == rhs.y) && (z == rhs.z))
		return true;
	else
		return false;
}

double skmult(const vec3d& rhs, const vec3d& lhs)
{
	double skmult = rhs.x*lhs.x + rhs.y*lhs.y + rhs.z*lhs.z;
	return skmult;
}

vec3d vecmult(const vec3d& rhs, const vec3d& lhs)
{
	vec3d vecmult;
	vecmult.x = rhs.y*lhs.z - rhs.z*lhs.y;
	vecmult.y = rhs.x*lhs.z - rhs.z*lhs.x;
	vecmult.z = rhs.z*lhs.y - rhs.y*lhs.x;
	return vecmult;
}


vec3d operator+(const vec3d& rhs, const vec3d& lhs)
{
	vec3d sum(rhs);
	sum += lhs;
	return sum;
}

vec3d operator-(const vec3d& rhs, const vec3d& lhs)
{
	vec3d dif(rhs);
	dif -= lhs;
	return dif;
}

vec3d operator*(const double rhs, const vec3d& lhs)
{
	vec3d mult(lhs);
	mult *= rhs;
	return mult;
}

vec3d operator*(const vec3d& rhs, const double lhs)
{
	vec3d mult(rhs);
	mult *= lhs;
	return mult;
}

vec3d operator/(const vec3d& rhs, const double lhs)
{
	vec3d rez(rhs);
	rez /= lhs;
	return rez;
}

vec3d& vec3d::operator+=(const vec3d& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

vec3d& vec3d::operator-=(const vec3d& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

vec3d& vec3d::operator*=(const double rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

vec3d& vec3d::operator/=(const double rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}

std::ostream& vec3d::writeTo(std::ostream& ostrm) const
{
	ostrm << x << separator << y << separator << z;
	return ostrm;
}

std::istream& vec3d::readFrom(std::istream& istrm)
{
	double x_(0.0);
	char comma(0);
	double y_(0.0);
	double z_(0.0);
	istrm >> x_ >> comma >> y_ >> comma >> z_;
	if (istrm.good()) {
		if ((vec3d::separator == comma)){
			x = x_;
			y = y_;
			z = z_;
		}
		else{
			istrm.setstate(std::ios_base::failbit);
		}
		return istrm;
	}
}