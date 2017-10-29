#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>
#include <iosfwd>
#include <sstream>

struct point2d
{
	point2d() = default;
	~point2d() = default;
	point2d(const double kx_, const double ky_);
	bool operator==(const point2d& rhs);
	bool operator!=(const point2d& rhs) { return !operator==(rhs); }
	point2d& operator+=(const point2d& rhs);
	point2d& operator-=(const point2d& rhs);
	point2d& operator*=(const double rhs);
	point2d& operator/=(const double rhs);
	point2d& changex();
	point2d& changey();
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	double kx{ 0.0 };
	double ky{ 0.0 };

	static const char separator{ ',' };
};

point2d operator+(const point2d& rhs, const point2d& lhs);
point2d operator-(const point2d& rhs, const point2d& lhs);
point2d operator*(const double rhs, const point2d& lhs);
point2d operator*(const point2d& rhs, const double lhs);
point2d operator/(const point2d& rhs, const double lhs);

inline std::ostream& operator<<(std::ostream& ostrm, const point2d& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, point2d& rhs)
{
	return rhs.readFrom(istrm);
}
#endif