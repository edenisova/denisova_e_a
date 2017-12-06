#include <iostream>
#include <sstream>
#include "stackl.h"

stackl::~stackl()
{
	while (!isEmpty())
		pop();
}

bool stackl::isEmpty() const
{
	return pHead_ == nullptr;
}

int& stackl::top()
{
	return pHead_->data_;
}

const int& stackl::top() const
{
	return pHead_->data_;
}

void stackl::push(const int& rhs)
{
	pHead_ = new Node(pHead_, rhs);
}

void stackl::pop()
{
	if (!isEmpty)
	{
		Node* pDel(pHead_);
		pHead_ = pHead_->pNext_;
		delete pDel;
	}
}

/*std::ostream& stackl::writeTo(std::ostream& ostrm) const
{
	while (!isEmpty())
	{
		ostrm << << endl;
	}
	return ostrm;
}*\

