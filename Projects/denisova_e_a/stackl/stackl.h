#ifndef STACKL_H
#define STACKL_H
#include <iostream>
#include <iosfwd>

using namespace std;

class stackl
{
public:
	stackl() = default;
	~stackl();
	void push(const int& rhs);
	void pop();
	int& top();
	const int& top() const;
	bool isEmpty() const;
	stackl& operator=(const stackl& rhs);
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);
private:
	struct Node
	{
		Node* pNext_{ nullptr };
		int data_{ 0 };
		Node(Node* pNode, const int& rhs) : pNext_{ pNode }, data_{ rhs } {};
	};
	Node* pHead_{ nullptr };
};

inline std::ostream& operator<<(std::ostream& ostrm, const stackl& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, stackl& rhs)
{
	return rhs.readFrom(istrm);
}

#endif