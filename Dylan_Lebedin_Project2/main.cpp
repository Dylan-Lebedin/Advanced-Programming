#include "Matrix.h"
#include <iostream>
using namespace std;

int main() {
	int rows1;
	int cols1;

	int rows2;
	int cols2;

	cout << "Enter the number of rows of matrix 1: ";
	cin >> rows1;
	cout << "Enter the number of columns of matrix 1: ";
	cin >> cols1;

	cout << "Enter the number of rows of matrix 2: ";
	cin >> rows2;
	cout << "Enter the number of columns of matrix 2: ";
	cin >> cols2;

	Matrix matrix1(rows1, cols1);
	Matrix matrix2(rows2, cols2);

	cout << "Enter data for matrix 1";
	cin >> matrix1;

	cout << "Enter data for matrix 2";
	cin >> matrix2;

	cout << "Matrix multiplication for the two matrices is: " << matrix1 * matrix2 << endl;

	system("pause");
	return 0;
}