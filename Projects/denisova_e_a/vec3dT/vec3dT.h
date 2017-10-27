#ifndef VEC3DT_H
#define VEC3DT_H
#include <iostream>
#include <iosfwd>
#include <sstream>

template<typename T>
struct vec3dT
{
public:
	vec3dT(const T& x_, const T& y_, const T& z_);
	vec3dT() = default;
	~vec3dT() = default;
	bool operator ==(const vec3dT& rhs) const;
	bool operator !=(const vec3dT& rhs) const { return !operator==(rhs); }
	vec3dT& operator+=(const vec3dT& rhs);
	vec3dT& operator-=(const vec3dT& rhs);
	vec3dT& operator*=(const T rhs);
	vec3dT& operator/=(const T rhs);
	vec3dT& operator=(const vec3dT& rhs) = default;
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	T x{ T() };
	T y{ T() };
	T z{ T() };

	static const char separator{ ',' };
};

template<typename T>
vec3dT<T> operator+(const vec3dT<T>& rhs, const vec3dT<T>& lhs);
template<typename T>
vec3dT<T> operator-(const vec3dT<T>& rhs, const vec3dT<T>& lhs);
template<typename T>
vec3dT<T> operator*(const T& rhs, const vec3dT<T>& lhs);
template<typename T>
vec3dT<T> operator*(const vec3dT<T>& rhs, const T& lhs);
template<typename T>
vec3dT<T> operator/(const vec3dT<T>& rhs, const T& lhs);
template<typename T>
T skmult(const vec3dT<T>& rhs, const vec3dT<T>& lhs);
template<typename T>
vec3dT<T> vecmult(const vec3dT<T>& rhs, const vec3dT<T>& lhs);


template<typename T>
inline std::ostream& operator<<(std::ostream& ostrm, const vec3dT<T>& rhs)
{
	return rhs.writeTo(ostrm);
}

template<typename T>
inline std::istream& operator>>(std::istream& istrm, vec3dT<T>& rhs)
{
	return rhs.readFrom(istrm);
}

template<typename T>
vec3dT<T>::vec3dT(const T x_, const T y_, const T z_) : x(x_), y(y_), z(z_){ }

template<typename T>
bool vec3dT<T>::operator==(const vec3dT<T>& rhs)const
{
	if ((x == rhs.x) && (y == rhs.y) && (z == rhs.z))
		return true;
	else
		return false;
}

template<> 
bool vec3dT<double>::operator==(const vec3dT<double>& rhs)const
{
	const double eps(0.00001);
	return ((abs(x - rhs.x) < eps) && (abs(y - rhs.y) < eps) && (abs(z - rhs.z) < eps));
}

template<typename T>
T skmult(const vec3dT<T>& rhs, const vec3dT<T>& lhs)
{
	T skmult = rhs.x*lhs.x + rhs.y*lhs.y + rhs.z*lhs.z;
	return skmult;
}

template<typename T>
vec3dT<T> vecmult(const vec3dT<T>& rhs, const vec3dT<T>& lhs)
{
	vec3dT<T> vecmult;
	vecmult.x = rhs.y*lhs.z - rhs.z*lhs.y;
	vecmult.y = rhs.x*lhs.z - rhs.z*lhs.x;
	vecmult.z = rhs.z*lhs.y - rhs.y*lhs.x;
	return vecmult;
}

template<typename T>
vec3dT<T> operator+(const vec3dT<T>& rhs, const vec3dT<T>& lhs)
{
	vec3dT<T> sum(rhs);
	sum += lhs;
	return sum;
}

template<typename T>
vec3dT<T> operator-(const vec3dT<T>& rhs, const vec3dT<T>& lhs)
{
	vec3dT<T> dif(rhs);
	dif -= lhs;
	return dif;
}

template<typename T>
vec3dT<T> operator*(const T& rhs, const vec3dT<T>& lhs)
{
	vec3dT<T> mult(lhs);
	mult *= rhs;
	return mult;
}

template<typename T>
vec3dT<T> operator*(const vec3dT<T>& rhs, const T& lhs)
{
	vec3dT<T> mult(rhs);
	mult *= lhs;
	return mult;
}

template<typename T>
vec3dT<T> operator/(const vec3dT<T>& rhs, const T& lhs)
{
	vec3dT<T> rez(rhs);
	rez /= lhs;
	return rez;
}

template<typename T>
vec3dT<T>& vec3dT<T>::operator+=(const vec3dT<T>& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

template<typename T>
vec3dT<T>& vec3dT<T>::operator-=(const vec3dT<T>& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

template<typename T>
vec3dT<T>& vec3dT<T>::operator*=(const T rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

template<typename T>
vec3dT<T>& vec3dT<T>::operator/=(const T rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}

template<typename T>
std::ostream& vec3dT<T>::writeTo(std::ostream& ostrm) const
{
	ostrm << x << separator << y << separator << z;
	return ostrm;
}

template<typename T>
std::istream& vec3dT<T>::readFrom(std::istream& istrm)
{
	T x_(0.0);
	char comma(0);
	T y_(0.0);
	T z_(0.0);
	istrm >> x_ >> comma >> y_ >> comma >> z_;
	if (istrm.good()) {
		if ((vec3dT<T>::separator == comma)){
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
#endif