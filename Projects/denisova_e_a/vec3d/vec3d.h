#ifndef VEC3D_H
#define VEC3D_H
#include <iostream>
#include <iosfwd>
#include <sstream>

struct vec3d
{
public:
	vec3d() = default;
	~vec3d() = default;
	vec3d(const double x_, const double y_, const double z_);
	bool operator ==(const vec3d& rhs);
	bool operator !=(const vec3d& rhs) { return !operator==(rhs); }
	vec3d& operator+=(const vec3d& rhs);
	vec3d& operator-=(const vec3d& rhs);
	vec3d& operator*=(const double rhs);
	vec3d& operator/=(const double rhs);
	vec3d& operator=(const vec3d& rhs) = default;
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	double x;
	double y;
	double z;

	static const char separator{ ',' };
};

vec3d operator+(const vec3d& rhs, const vec3d& lhs);
vec3d operator-(const vec3d& rhs, const vec3d& lhs);
vec3d operator*(const double rhs, const vec3d& lhs);
vec3d operator*(const vec3d& rhs, const double lhs);
vec3d operator/(const vec3d& rhs, const double lhs);
double skmult(const vec3d& rhs, const vec3d& lhs);
vec3d vecmult(const vec3d& rhs, const vec3d& lhs);



inline std::ostream& operator<<(std::ostream& ostrm, const vec3d& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, vec3d& rhs)
{
	return rhs.readFrom(istrm);
}

#endif