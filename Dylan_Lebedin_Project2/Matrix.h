#pragma once
#ifndef Matrix_hpp
#define Matrix_hpp
#include <iostream>
using namespace std;

class Matrix
{	
private:
	int matrix_rows;
	int matrix_cols;
	int matrix_size;
	double **data;

public:
	//Matrix(); //default constructor, not going to be initalized in cpp
	Matrix(int rows, int cols); //constrctor that takes in rows and columns
	Matrix(const Matrix & matrix); //copy constructor

	
	Matrix operator+(const Matrix& matrix); //overloaded binary '+' operator
	Matrix operator-(const Matrix& matrix); //overloaded binary '-' operator
	Matrix operator*(const Matrix& matrix); //overloaded binary '*' operator

	Matrix operator+=(const Matrix& matrix); //overloaded assignment operator '+='
	Matrix operator-=(const Matrix& matrix); //overloaded assignment operator '-='

	friend istream& operator >>(istream& inputstream, const Matrix& matrix); //overloaded input operator
	friend ostream& operator<<(ostream& outstream, const Matrix& matrix); //overloaded output operator


	void operator=(const Matrix& matrix); //overloaded assignment operator

	Matrix operator++ (); //overloaded prefix ++
	Matrix operator-- (); //overloaded prefix --
	Matrix operator++(int); //overloaded postfix ++
	Matrix operator--(int); //overloaded postfix --

	~Matrix();
};

#endif