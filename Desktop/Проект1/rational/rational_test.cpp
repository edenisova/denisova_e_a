#include "rational.h"
#include <iostream>
#include <sstream>

int main()
{
	using namespace std;
	Rational ratio(3, 6);
	Rational ratio1(1, -1);
	cout << ratio << "\n" << ratio1 << endl;
	Rational ratio2(4, 2);
	Rational ratio3(1, 4);
	Rational sum = ratio1 + ratio2;
	cout << ratio1 << '+' << ratio2 << '=' << sum << endl;
	int c = 5;
	cout << ratio;
	ratio += c;
	cout << '+' << c << '=' << ratio << endl;
	cout << ratio3;
	ratio3 += ratio;
	cout << '+' << ratio << '=' << ratio3 << endl;
	Rational ratio4(1, 3);
	Rational diff = ratio - ratio4;
	cout << ratio << '-' << ratio4 << '=' << diff << endl;
	cout << ratio3;
	ratio3 -= c;
	cout << '-' << c << '=' << ratio3 << endl;
	cout << ratio4;
	ratio4 -= ratio;
	cout << '-' << ratio << '=' << ratio4 << endl;
	Rational mul = ratio*ratio1;
	cout << ratio << '*' << ratio1 << '=' << mul << endl;
	cout << ratio4;
	ratio4 *= c;
	cout << '*' << c << '=' << ratio4 << endl;
	cout << ratio3;
	ratio3 *= ratio2;
	cout << '*' << ratio2 << '=' << ratio3 << endl;
	Rational div = ratio1 / ratio4;
	cout << ratio1 << '/' << ratio4 << '=' << div << endl;
	cout << ratio3;
	ratio3 /= c;
	cout << '/' << '{' << c << '}' << '=' << ratio3 << endl;
	cout << ratio2;
	ratio2 /= ratio3;
	cout << '/' << ratio3 << '=' << ratio2 << endl;
	Rational ratio5(2, 3);
	Rational ratio6(4, 3);
	Rational ratio7(5, 3);
	cout << (ratio7 > ratio6) << endl;
	cout << (ratio5 > ratio6) << endl;
	cout << (ratio7 >= ratio6) << endl;
	cout << (ratio6 >= ratio6) << endl;
	cout << (ratio5 >= ratio6) << endl;
	cout << (ratio5 < ratio6) << endl;
	cout << (ratio7 < ratio6) << endl;
	cout << (ratio7 <= ratio6) << endl;
	cout << (ratio6 <= ratio6) << endl;
	cout << (ratio5 <= ratio6) << endl;
	int k = 4;
	cout << (k + ratio6) << endl;
	cout << (ratio6 + k) << endl;
	cout << (k - ratio7) << endl;
	cout << (ratio7 - k) << endl;
	cout << (k * ratio5) << endl;
	cout << (ratio5 * k) << endl;
	cout << (k / ratio5) << endl;
	cout << (ratio5 / k) << endl;
	system("pause");
	return 0;
}