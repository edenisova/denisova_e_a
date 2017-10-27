#include "vec3dT.h"
#include <iostream>
#include <sstream>

int main()
{
	using namespace std;
	vec3dT<double> a(10.5, 3.6, 4.7);
	vec3dT<double> b(2.5, 3.7, 1.8);
	vec3dT<double> d(11.0, 12.8, 14.5);
	double c(3.5);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "d = " << d << endl;
	cout << "c = " << c << endl;
	cout << endl;
	bool m = a == b;
	cout << "a == b : " << m << endl;
	m = b == b;
	cout << "b == b : " << m << endl;
	cout << endl;
	m = a != a;
	cout << "a != a : " << m << endl;
	m = a != b;
	cout << "a != b : " << m << endl;
	vec3dT<double> sum = a + b;
	cout << "a + b = " << sum << endl;
	cout << endl;
	cout << " a += b -> ";
	a += b;
	cout << a << endl;
	cout << endl;
	cout << " d -= b -> ";
	d -= b;
	cout << d << endl;
	cout << endl;
	vec3dT<double> diff = a - b;
	cout << "a - b = " << diff << endl;
	cout << endl;
	vec3dT<double> mult = b * c;
	cout << "b * c = " << mult << endl;
	cout << endl;
	cout << " d *= c -> ";
	d *= c;
	cout << d << endl;
	cout << endl;
	vec3dT<double> mult1 = c * b;
	cout << "c * b = " << mult1 << endl;
	cout << endl;
	double rez1 = skmult(a, b);
	cout << "ScalarMultiplication : a * b = " << rez1 << endl;
	cout << endl;
	vec3dT<double> rez2 = vecmult(a, d);
	cout << "VecMultiplication : a * d = " << rez2 << endl;
	cout << endl;
	vec3dT<double> quot = a / c;
	cout << "a / c = " << quot << endl;
	cout << endl;
	cout << " a /= c -> ";
	a /= c;
	cout << a << endl;
	cout << endl;
	char exit;
	cin >> exit;
	return 0;
}