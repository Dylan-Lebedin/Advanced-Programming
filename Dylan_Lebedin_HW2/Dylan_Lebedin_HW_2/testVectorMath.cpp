#include <vector>
#include "VectorMath.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int y = 1;
	while (y > 0) {
		int dim;
		int operation;
		string response;

		double i1, j1, k1, i2, j2, k2;
		vector<double> v1;
		vector<double> v2;
		vector<double> output;
		double mag1;
		double mag2;
		double dotVec;
		double dotArr;
		cout << "Enter Number of Vector Components: ";
		cin >> dim;

		double a[3];
		double b[3];
		double out[3];
		cout << "\n\nOperations Available:\n(0) Addition\n(1) Subtraction\n(2) Magnitude\n(3) Dot Product\n(4) Cross Product";
		cout << "\n\nPlease select an operation: ";
		cin >> operation;

		switch (operation) {
		case 0:
			cout << "Enter Component Values of Vector 1";
			for (int i = 0; i < dim; i++) {
				if (i == 0) {
					cout << "\ni: ";
					cin >> i1;
					v1.push_back(i1);
					a[i] = i1;
				}
				else if (i == 1) {
					cout << "j: ";
					cin >> j1;
					v1.push_back(j1);
					a[i] = j1;
				}
				else {
					cout << "k: ";
					cin >> k1;
					v1.push_back(k1);
					a[i] = k1;
				}
			}
			cout << "\n\nEnter component Values of Vector 2";
			for (int i = 0; i < dim; i++) {
				if (i == 0) {
					cout << "\ni: ";
					cin >> i2;
					v2.push_back(i2);
					b[i] = i2;
				}
				else if (i == 1) {
					cout << "j: ";
					cin >> j2;
					v2.push_back(j2);
					b[i] = j2;
				}
				else {
					cout << "k: ";
					cin >> k2;
					v2.push_back(k2);
					b[i] = k2;
				}
			}

			addArray(a, b, out, dim);
			output = addVector(v1, v2);

			if (dim == 1) {
				cout << "\n\nArray Result: \n\n";
				cout << "i: " << out[0];
				cout << "\n\nVector Result: \n\n";
				cout << "i: " << output.at(0);
			}
			
			else if (dim == 2) {
				cout << "\n\nArray Result: \n\n";
				cout << "i: " << out[0];
				cout << "\nj: " << out[1];

				cout << "\n\nVector Result: \n\n";
				cout << "i: " << output.at(0);
				cout << "\nj: " << output.at(1);
			}
			
			else {
				cout << "\n\nArray Result: \n\n";
				cout << "i: " << out[0];
				cout << "\nj: " << out[1];
				cout << "\nk: " << out[2];

				cout << "\n\nVector Result: \n\n";
				cout << "i: " << output.at(0);
				cout << "\nj: " << output.at(1);
				cout << "\nk: " << output.at(2);
			}
			break;

			case 1:
				cout << "Enter Component Values of Vector 1";
				for (int i = 0; i < dim; i++) {
					if (i == 0) {
						cout << "\ni: ";
						cin >> i1;
						v1.push_back(i1);
						a[i] = i1;
					}
					else if (i == 1) {
						cout << "j: ";
						cin >> j1;
						v1.push_back(j1);
						a[i] = j1;
					}
					else {
						cout << "k: ";
						cin >> k1;
						v1.push_back(k1);
						a[i] = k1;
					}
				}
				cout << "\n\nEnter component Values of Vector 2";
				for (int i = 0; i < dim; i++) {
					if (i == 0) {
						cout << "\ni: ";
						cin >> i2;
						v2.push_back(i2);
						b[i] = i2;
					}
					else if (i == 1) {
						cout << "j: ";
						cin >> j2;
						v2.push_back(j2);
						b[i] = j2;
					}
					else {
						cout << "k: ";
						cin >> k2;
						v2.push_back(k2);
						b[i] = k2;
					}
				}

				subArray(a, b, out, dim);
				output = subVector(v1, v2);

				if (dim == 1) {
					cout << "\n\nArray Result: \n\n";
					cout << "i: " << out[0];
					cout << "\n\nVector Result: \n\n";
					cout << "i: " << output.at(0);
				}

				else if (dim == 2) {
					cout << "\n\nArray Result: \n\n";
					cout << "i: " << out[0];
					cout << "\nj: " << out[1];

					cout << "\n\nVector Result: \n\n";
					cout << "i: " << output.at(0);
					cout << "\nj: " << output.at(1);
				}

				else {
					cout << "\n\nArray Result: \n\n";
					cout << "i: " << out[0];
					cout << "\nj: " << out[1];
					cout << "\nk: " << out[2];

					cout << "\n\nVector Result: \n\n";
					cout << "i: " << output.at(0);
					cout << "\nj: " << output.at(1);
					cout << "\nk: " << output.at(2);
				}
				break;


			case 2:
				cout << "Enter Component Values of Vector 1";
				for (int i = 0; i < dim; i++) {
					if (i == 0) {
						cout << "\ni: ";
						cin >> i1;
						v1.push_back(i1);
						a[i] = i1;
					}
					else if (i == 1) {
						cout << "j: ";
						cin >> j1;
						v1.push_back(j1);
						a[i] = j1;
					}
					else if (i == 2) {
						cout << "k: ";
						cin >> k1;
						v1.push_back(k1);
						a[i] = k1;
					}
				}

				mag1 = magArray(a, out, dim);
				mag2 = magVector(v1);

				cout << "\n\nArray Result: \n\n" << mag1;

				cout << "\n\nVector Result: \n\n" << mag2;
	
				break;
			case 3:

				cout << "Enter Component Values of Vector 1";
				for (int i = 0; i < dim; i++) {
					if (i == 0) {
						cout << "\ni: ";
						cin >> i1;
						v1.push_back(i1);
						a[i] = i1;
					}
					else if (i == 1) {
						cout << "j: ";
						cin >> j1;
						v1.push_back(j1);
						a[i] = j1;
					}
					else {
						cout << "k: ";
						cin >> k1;
						v1.push_back(k1);
						a[i] = k1;
					}
				}
				cout << "\n\nEnter component Values of Vector 2";
				for (int i = 0; i < dim; i++) {
					if (i == 0) {
						cout << "\ni: ";
						cin >> i2;
						v2.push_back(i2);
						b[i] = i2;
					}
					else if (i == 1) {
						cout << "j: ";
						cin >> j2;
						v2.push_back(j2);
						b[i] = j2;
					}
					else {
						cout << "k: ";
						cin >> k2;
						v2.push_back(k2);
						b[i] = k2;
					}
				}

				dotArr = dotArray(a, b, dim);
				dotVec = dotVector(v1, v2);

				
					cout << "\n\nArray Result: \n\n";
					cout << dotArr;
					cout << "\n\nVector Result: \n\n";
					cout <<  dotVec;

				break;

			case 4:
				if (dim != 3) {
					cout << "Please Enter Valid Number of Vector Components: ";
					cin >> dim;
				}

				cout << "Enter Component Values of Vector 1";
				for (int i = 0; i < 3; i++) {
					if (i == 0) {
						cout << "\ni: ";
						cin >> i1;
						v1.push_back(i1);
						a[i] = i1;
					}
					else if (i == 1) {
						cout << "j: ";
						cin >> j1;
						v1.push_back(j1);
						a[i] = j1;
					}
					else {
						cout << "k: ";
						cin >> k1;
						v1.push_back(k1);
						a[i] = k1;
					}
				}
				cout << "\n\nEnter component Values of Vector 2";
				for (int i = 0; i < 3; i++) {
					if (i == 0) {
						cout << "\ni: ";
						cin >> i2;
						v2.push_back(i2);
						b[i] = i2;
					}
					else if (i == 1) {
						cout << "j: ";
						cin >> j2;
						v2.push_back(j2);
						b[i] = j2;
					}
					else {
						cout << "k: ";
						cin >> k2;
						v2.push_back(k2);
						b[i] = k2;
					}
				}

				crossArray(a, b, out);
				output = crossVector(v1, v2);

					cout << "\n\nArray Result: \n\n";
					cout << "i: " << out[0];
					cout << "\nj: " << out[1];
					cout << "\nk: " << out[2];

					cout << "\n\nVector Result: \n\n";
					cout << "i: " << output.at(0);
					cout << "\nj: " << output.at(1);
					cout << "\nk: " << output.at(2);
					
				break;	
		}


		cout << "\nTry New (Y/N)? ";
		cin >> response;

		if (!response.compare("Y")) {
			y = 1;
		}
		else if (!response.compare("N")) {
			y = 0;
		}
		
		

	}
	cout << "*** Program Terminated ***";
}