#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <iosfwd>

class Array
{
public:
	Array() = default;
	~Array();
	Array(const int rhs);
	Array& operator=(const Array& rhs) = default;
	void add(const int rhs);
	void insert(const int rhs, const int lhs);
	void remote(const int rhs, const int lhs);
	void resize(const int rhs);
	int& operator[](const ptrdiff_t i);
	const int& operator[](const ptrdiff_t& i) const;
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);
private:
	ptrdiff_t capacity_{ 0 };
	ptrdiff_t size_{ 0 };
	int* pdata{ nullptr };
};

inline std::ostream& operator<<(std::ostream& ostrm, const Array& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Array& rhs)
{
	return rhs.readFrom(istrm);
}
#endif