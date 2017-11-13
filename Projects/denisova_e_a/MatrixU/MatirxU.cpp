#include <iostream>
#include <sstream>
#include "matrixu.h"

using namespace std;

MatrixU::~MatrixU()
{
	delete[] pData_;
	pData_ = nullptr;
	nRow = ptrdiff_t{ 0 };
	nCol = ptrdiff_t{ 0 };
}

MatrixU::MatrixU(const ptrdiff_t nRow, const ptrdiff_t nCol)
{
	if ((nRow > 0) && (nCol > 0))
	{
		pData_ = new int[nRow*nCol];
	}
	for (int i = 0; i < nRow*nCol; i++)
	{
		*(pData_ + i) = 0;
	}
}

int& MatrixU::at(ptrdiff_t iRow, ptrdiff_t iCol)
{
	try
	{
		if ((iRow < nRow) && (iCol < nCol))
		{
			return *(pData_ + nCol*iRow + iCol);
		}
		else
		{
			throw invalid_argument("неверный индекс");
		}
	}
	catch (char *invalid_argument)
	{
		cout << invalid_argument << endl;
	}
}

const int& MatrixU::at(ptrdiff_t iRow, ptrdiff_t iCol) const
{
	return at(iRow, iCol);
}

MatrixU operator+(const MatrixU& rhs, const MatrixU& lhs)
{
	MatrixU sum;
	if ((rhs.nRow == lhs.nRow)&&(rhs.nCol == lhs.nCol))
	{
		for (int i = 0; i < rhs.nRow; i++)
		{
			for (int j = 0; j < rhs.nCol; j++)
			{
				sum.at(i, j) = rhs.at(i, j) + lhs.at(i, j);
			}
		}
	}
	return sum;
}

