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
	Complex a(2.0, 3.5);
	Complex b(3.9, 4.5);
	Complex c(5.6, 6.2);
	double d(3.0);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << endl;
	Complex test1(2.5, 3.4);
	Complex test2(4.5);
	cout << "test1 = " << test1 << endl;
	cout << "test2 = " << test2 << endl;
	cout << endl;
	Complex rez = a + b;
	cout << a << " + " << b << " -> " << rez << endl;
	cout << endl;
	cout << a << " += " << d << " -> ";
	a += d;
	cout << a << endl;
	cout << endl;
	cout << b << " += " << c << " -> ";
	b += c;
	cout << b << endl;
	cout << endl;
	Complex diff = b - c;
	cout << b << " - " << c << " -> " << diff << endl;
	cout << endl;
	cout << b << " -= " << d << " -> ";
	b -= d;
	cout << b << endl;
	cout << endl;
	cout << c << " -= " << a << " -> ";
	c -= a;
	cout << c << endl;
	cout << endl;
	Complex mult = b * c;
	cout << b << " * " << c << " -> " << mult << endl;
	cout << endl;
	cout << a << " *= " << d << " -> ";
	a *= d;
	cout << a << endl;
	cout << endl;
	cout << c << " *= " << a << " -> ";
	c *= a;
	cout << c << endl;
	cout << endl;
	Complex quot = a/b;
	cout << a << " / " << b << " -> " << quot << endl;
	cout << endl;
	cout << b << " /= " << d << " -> ";
	b /= d;
	cout << b << endl;
	cout << endl;
	cout << a << " /= " << c << " -> ";
	a /= c;
	cout << a << endl;
	cout << endl;
	Complex e(3.5, 4.2);
	Complex f(3.4, 5.5);
	double k(2.0);
	rez = e + k;
	Complex rez1 = k + e;
	cout << e << '+' << k << '=' << rez << endl;
	cout << endl;
	cout << k << '+' << e << '=' << rez1 << endl;
	cout << endl;
	rez = f - k;
	rez1 = k - f;
	cout << f << '-' << k << '=' << rez << endl;
	cout << endl;
	cout << k << '-' << f << '=' << rez1 << endl;
	cout << endl;
	rez = e * k;
	rez1 = k * e;
	cout << e << '*' << k << '=' << rez << endl;
	cout << endl;
	cout << k << '*' << e << '=' << rez1 << endl;
	cout << endl;
	rez = f/k;
	rez1 = k/f;
	cout << f << '/' << k << '=' << rez << endl;
	cout << endl;
	cout << k << '/' << f << '=' << rez1 << endl;
	cout << endl;
	bool m = e == f;
	cout << e << "==" << f << ':' << m << endl;
	cout << endl;
	m = e == e;
	cout << e << "==" << e << ':' << m << endl;
	cout << endl;
	m = e != e;
	cout << e << "!=" << e << ':' << m << endl;
	cout << endl;
	m = e != f;
	cout << e << "!=" << f << ':' << m << endl;
	cout << endl;
	cout << 'e' << '=' << e << endl;
	cout << "++" << "e" << '=' << ++e << endl;
	cout << endl;
	cout << 'e' << '=' << e << endl;
	cout << "--" << "e" << '=' << --e << endl;
	cout << endl;
	cout << 'e' << '=' << e << endl;
	e++;
	cout << "e" << "++" << '=' << e << endl;
	cout << endl;
	cout << 'e' << '=' << e << endl;
	e--;
	cout << "e" << "--" << '=' << e << endl;
	char exit;
	cin >> exit;
	return 0;
}
