#include "complex.h"
#include <iostream>
#include <sstream>



bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Complex z;
	istrm >> z;
	if (istrm.good()){
		cout << "read success: " << str << "->" << z << endl;
	}
	else {
		cout << "read error: " << str << "->" << z << endl;
	}
	return istrm.good();
}

int main()
{
	using namespace std;
	testParse("{8.9,9}");
	testParse("{8.9, 9}");
	testParse("{8.9,9");
	Complex a(2.0, 0);
	Complex b(3.9, 4.5);
	Complex c(5.6, 6.2);
	double d(3.0);
	Complex rez = a + b;
	cout << a << '+' << b << '=' << rez << endl;
	cout << a;
	a += d;
	cout << '+' << d << '=' << a << endl;
	cout << b;
	b += c;
	cout << '+' << c << '=' << b << endl;
	Complex diff = b - c;
	cout << b << '-' << c << '=' << diff << endl;
	cout << b;
	b -= d;
	cout << '-' << d << '=' << b << endl;
	cout << c;
	c -= a;
	cout << '-' << a << '=' << c << endl;
	Complex rez1 = b*c;
	cout << b << '*' << c << '=' << rez1 << endl;
	cout << a;
	a *= d;
	cout << '*' << d << '=' << a << endl;
	cout << c;
	c *= a;
	cout << '*' << a << '=' << c << endl;
	Complex rez2 = a / b;
	cout << a << '/' << b << '=' << rez2 << endl;
	cout << b;
	b /= d;
	cout << '/' << d << '=' << b << endl;
	cout << a;
	a /= c;
	cout << '/' << c << '=' << a << endl;
	Complex e(3.5, 4.2);
	Complex f(3.4, 5.5);
	double k(2.0);
	cout << (e + k) << endl;
	cout << (k + e) << endl;
	cout << (f - k) << endl;
	cout << (k - f) << endl;
	cout << (e * k) << endl;
	cout << (k * e) << endl;
	cout << (f / k) << endl;
	cout << (k / f) << endl;
	cout << (e == f) << endl;
	cout << (e == e) << endl;
	system("pause");
	return 0;
}
