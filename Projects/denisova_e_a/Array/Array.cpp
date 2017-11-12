#include "Array.h"
#include <iostream>
#include <sstream>

using namespace std;

Array::~Array()
{
	delete[] pdata;
	pdata = nullptr;
	capacity_ = ptrdiff_t{ 0 };
	size_ = ptrdiff_t{ 0 };
}

Array::Array(const int rhs)
{
	capacity_ = rhs;
	pdata = new int[capacity_];
	for (int i = 0; i < capacity_; i++)
	{
		*(pdata + i) = 0;
		size_++;
	}
}

int& Array::operator[](const ptrdiff_t i)
{
	if ((i>0)&&(i < capacity_))
	{
		return pdata[i];
	}
	else
	{
		try
		{
			if ((i < 0) && (i >= capacity_))
			{
				throw invalid_argument("неверный индекс");
			}
		}
		catch (char *invalid_argument)
		{
			cout << invalid_argument << endl;
		}
	}
}

const int& Array::operator[](const ptrdiff_t& i) const
{
	return operator[](i);
}

void Array::insert(const int rhs, const int lhs)
{
	if ((lhs >= 0) && (lhs < size_))
	{
		if (size_ >= capacity_)
		{
			capacity_++;
			int* newpdata = new int[capacity_];
			for (int i = 0; i < lhs; i++)
			{
				*(newpdata + i) = *(pdata + i);
			}
			for (int i = lhs + 1; i < capacity_ + 1; i++)
			{
				*(newpdata + i) = *(pdata + i - 1);
			}
			*(newpdata + lhs) = rhs;
			pdata = newpdata;
			size_++;
		}
		else
		{
			for (int i = lhs + 1; i < size_ + 1; i++)
			{
				*(pdata + i) = *(pdata + i - 1);
			}
			*(pdata + lhs) = rhs;
			size_++;
		}
	}
}

void Array::add(const int rhs)
{
	if (size_ >= capacity_)
	{
		capacity_++;
		int* newpdata = new int[capacity_];
		for (int i = 0; i < size_; i++)
		{
			*(newpdata + i) = *(pdata + i);
		}
		*(newpdata + size_) = rhs;
		pdata = newpdata;
		size_++;
	}
	else
	{
		*(pdata + size_) = rhs;
		size_++;
	}
}

void Array::remote(const int rhs, const int lhs)
{
	if ((lhs >= 0) && (lhs < size_))
	{
		for (int i = lhs; i < size_ - 1; i++)
		{
			*(pdata + i) = *(pdata + i + 1);
		}
		size_--;
	}
}

void Array::resize(const int rhs)
{
	if ((rhs > size_) && (rhs > capacity_))
	{
		capacity_ = rhs;
	}
	if ((rhs > size_) && (rhs < capacity_))
	{
		capacity_ = rhs;
	}
	if ((rhs < size_) && (rhs < capacity_) && (rhs > 0))
	{
		size_ = rhs;
		capacity_ = rhs;
	}
	if (rhs == 0)
	{
		Array::~Array();
	}
	try
	{
		if (rhs < 0)
		{
			throw invalid_argument("неверный индекс");
		}
	}
	catch (char *invalid_argument)
	{
		cout << invalid_argument << endl;
	}
}

std::ostream& Array::writeTo(std::ostream& ostrm) const
{
	for (int i = 0; i < size_; i++)
	{
		ostrm << *(pdata + i) << endl;
	}
	return ostrm;
}

std::istream& Array::readFrom(std::istream& istrm)
{
	int* newpdata = new int[capacity_];
	for (int i = 0; i < size_; i++)
	{
		istrm >> *(newpdata + i);
	}
	if (istrm.good())
	{
		pdata = newpdata;
	}
	return istrm;
}