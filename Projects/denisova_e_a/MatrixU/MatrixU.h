#ifndef MATRIXU_H
#define MATRIXU_H
#include <iostream>
#include <iosfwd>

class MatrixU
{
public:
	MatrixU() = default;
	~MatrixU();
	MatrixU(const ptrdiff_t nRow, const ptrdiff_t nCol);
	int& at(ptrdiff_t iRow, ptrdiff_t iCol);
	const int& at(ptrdiff_t iRow, ptrdiff_t iCol) const;
	MatrixU& operator=(const MatrixU& rhs) = default;
	ptrdiff_t nRow{ 0 };
	ptrdiff_t nCol{ 0 };
private:
	int* pData_{ nullptr };
};

MatrixU operator+(const MatrixU& rhs, const MatrixU& lhs);
MatrixU operator-(const MatrixU& rhs, const MatrixU& lhs);
MatrixU operator*(const MatrixU& rhs, const MatrixU& lhs);


#endif