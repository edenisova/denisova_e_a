#include "point2d.h"
#include <iostream>
#include <sstream>

int main()
{
	using namespace std;
	point2d a(2.3, 3.4);
	point2d b(5.5, 6.9);
	point2d d(6.9, 10.0);
	double c(4.0);
	bool m = a == a;
	cout << "a == a: " << m << endl;
	m = a != a;
	cout << "a != a: " << m << endl;
	m = a == b;
	cout << "a == b: " << m << endl;
	m = a != b;
	cout << " a != b: " << m << endl;
	cout << endl;
	point2d sum = a + b;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << endl;
	cout << " a " << "+" << " b " << "=" << sum << endl;
	cout << endl;
	cout << "a += b -> ";
	a += b;
	cout << a << endl;
	cout << endl;
	point2d dif = a - b;
	cout << "a - b = " << dif << endl;
	cout << endl;
	cout << " d -= b -> ";
	d -= b;
	cout << d << endl;
	cout << endl;
	point2d mult = c * b;
	cout << "c * b = " << mult << endl;
	cout << endl;
	point2d mult1 = b * c;
	cout << "b * c = " << mult1 << endl;
	cout << endl;
	cout << "b *= c -> ";
	b *= c;
	cout << b << endl;
	cout << endl;
	point2d rez = a / c;
	cout << "a/c = " << rez << endl;
	cout << endl;
	cout << "a /= c -> ";
	a /= c;
	cout << a << endl;
	cout << endl;
	b.changex();
	cout << "b.changex = " << b << endl;
	cout << endl;
	a.changey();
	cout << "a.changey = " << a << endl;
	point2d r;
	cin >> r;
}