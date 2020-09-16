#include "Matrix.h"
#include <iostream>
using namespace std;

//Matrix::Matrix() {}

Matrix::Matrix(int rows, int cols) {
	matrix_rows = rows;
	matrix_cols = cols;
	data = new double*[matrix_rows];
	for (int i = 0; i < matrix_rows; i++) {
		data[i] = new double[matrix_cols];
	}
	for (int i = 0; i < matrix_rows; i++) {
		for (int j = 0; j < matrix_cols; j++) {
			data[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix & matrix) : matrix_rows(matrix.matrix_rows), matrix_cols(matrix.matrix_cols){
	matrix_rows = matrix.matrix_rows;
	matrix_cols = matrix.matrix_cols;
	data = new double*[matrix_rows];
	for (int i = 0; i < matrix_rows; i++) {
		data[i] = new double[matrix_cols];
	}
	for (int i = 0; i < matrix_rows; i++) {
		for (int j = 0; j < matrix_cols; j++) {
			data[i][j] = matrix.data[i][j];
		}
	}
}

Matrix Matrix::operator+(const Matrix& matrix) {
	Matrix new_mat(matrix_rows, matrix_cols);
	for (int i = 0; i < matrix_rows; i++) {
		for (int j = 0; j < matrix_cols; j++) {
			new_mat.data[i][j] = data[i][j] + matrix.data[i][j];
		}
	}
	return new_mat;
}

Matrix Matrix::operator-(const Matrix& matrix) {
	Matrix new_mat(matrix_rows, matrix_cols);
	for (int i = 0; i < matrix_rows; i++) {
		for (int j = 0; j < matrix_cols; j++) {
			new_mat.data[i][j] = data[i][j] - matrix.data[i][j];
		}
	}
	return new_mat;
}

Matrix Matrix:: operator+= (const Matrix& matrix) {
	Matrix new_mat(matrix_rows, matrix_cols);
	for (int i = 0; i < matrix_rows; i++) {
		for (int j = 0; j < matrix_cols; j++) {
			new_mat.data[i][j] += data[i][j] + matrix.data[i][j];
		}
	}
	return new_mat;
}

Matrix Matrix:: operator-= (const Matrix& matrix) {
	Matrix new_mat(matrix_rows, matrix_cols);
	for (int i = 0; i < matrix_rows; i++) {
		for (int j = 0; j < matrix_cols; j++) {
			new_mat.data[i][j] -= data[i][j] + matrix.data[i][j];
		}
	}
	return new_mat;
}

Matrix Matrix:: operator*(const Matrix& matrix) {
	// first, make sure matrices can be multiplied. if not, return original matrix
	if (matrix_rows != matrix.matrix_rows || matrix_cols != matrix.matrix_cols) {
		cerr << "Matrix sizes do not match. Multiplication cannot be done";
		return (*this);
	}
	Matrix new_mat(matrix_rows, matrix_cols);
	for (int i = 0; i < matrix_rows; i++) {
		for (int j = 0; j < matrix.matrix_cols; j++) {
			for (int k = 0; k < matrix_cols; k++) {
				new_mat.data[i][j] = data[i][k] * matrix.data[k][j];
			}
		}
	}
	return new_mat;
}

Matrix Matrix:: operator++() { //prefix '++' operator
	Matrix new_mat(matrix_rows, matrix_cols);
	for (int i = 0; i < matrix_rows; i++) {
		for (int j = 0; j < matrix_cols; j++) {
			new_mat.data[i][j] = ++data[i][j];
		}
	}
	return new_mat;
}

Matrix Matrix:: operator--() { //prefix '--' operator
	Matrix new_mat(matrix_rows, matrix_cols);
	for (int i = 0; i < matrix_rows; i++) {
		for (int j = 0; j < matrix_cols; j++) {
			new_mat.data[i][j] = --data[i][j];
		}
	}
	return new_mat;
}

Matrix Matrix:: operator++(int) { //postfix '++' operator
	Matrix new_mat(matrix_rows, matrix_cols);
	for (int i = 0; i < matrix_rows; i++) {
		for (int j = 0; j < matrix_cols; j++) {
			new_mat.data[i][j] = data[i][j]++;
		}
	}
	return new_mat;
}

Matrix Matrix:: operator--(int) { //postfix '--' operator
	Matrix new_mat(matrix_rows, matrix_cols);
	for (int i = 0; i < matrix_rows; i++) {
		for (int j = 0; j < matrix_cols; j++) {
			new_mat.data[i][j] = data[i][j]--;
		}
	}
	return new_mat;
}

void Matrix :: operator=(const Matrix& matrix) {
	if (matrix_rows != matrix.matrix_rows || matrix_cols != matrix.matrix_cols) {
		cerr << "Matrix sizes do not match. Setting the matrix equal to each other cannot be done";
	}
	else {
		for (int i = 0; i < matrix_rows; i++) {
			for (int j = 0; j < matrix_cols; j++) {
				data[i][j] = matrix.data[i][j];
			}
		}
	}
}

istream& operator >>(istream& inputstream, const Matrix& matrix) {
	for (int i = 0; i < matrix.matrix_rows; i++) {
		for (int j = 0; j < matrix.matrix_cols; j++) {
			inputstream >> matrix.data[i][j];
		}
	}
	return inputstream;
} 
ostream& operator<<(ostream& outstream, const Matrix& matrix) {
	for (int i = 0; i < matrix.matrix_rows; i++) {
		for (int j = 0; j < matrix.matrix_cols; j++) {
			outstream << matrix.data[i][j] << ' ';
		}
	}
	return outstream;
}

Matrix::~Matrix()
{
	for (int i = 0; i < matrix_rows; i++) {
		delete[] data[i];
	}
	delete[] data;
}
