#include <vector>
#include <iostream>
#include "VectorMath.h"
#include <math.h>

void addArray(double a[], double b[], double out[], int dim) {
	for (int i = 0; i < dim; i++) {
		out[i] = a[i] + b[i];
	}

}

vector<double> addVector(vector<double> v1, vector<double> v2) {
	vector <double> sum;
	double elem1;
	double elem2;
	double elemsum;
	for (int i = 0; i < 3; i++) {
		v1.push_back(i);
		elem1 = v1.at(i);
		v2.push_back(i);
		elem2 = v2.at(i);
		elemsum = elem1 + elem2;
		sum.push_back(elemsum);
	}
	return sum;
}
 void subArray(double a[], double b [], double out [], int dim) {
	for (int i = 0; i < dim; i++) {
		out[i] = a[i] - b[i];
	}
}
vector<double> subVector(vector<double> v1, vector<double> v2) {
	vector <double> diff;
	double elem1;
	double elem2;
	double elemdiff;
	for (int i = 0; i < 3; i++) {
		v1.push_back(i);
		elem1 = v1.at(i);
		v2.push_back(i);
		elem2 = v2.at(i);
		elemdiff = elem1 - elem2;
		diff.push_back(elemdiff);
	}
	return diff;
}

double magArray(double a [], double out [], int dim) {
	double sum = 0;
	double mag = 0;
	for (int i = 0; i < dim; i++) {
		out[i] = a[i] * a[i];
		sum += out[i];
		mag = sqrt(sum);
	}
	return mag;
}
	double magVector(vector<double> v1) {
	double sum = 0;
	double element = 0;
	double mag = 0;
	for (int i = 0; i < 3; i++) {
		v1.push_back(i);
		element = v1.at(i);
		sum += element * element;
		mag = sqrt(sum);
	}
	return mag;
}

double dotArray(double a [], double b [], int dim) {
	double dot = 0;
	for (int i = 0; i < dim; i++) {
		dot += a[i] * b[i];
	}
	return dot;
}
double dotVector(vector<double> v1, vector<double> v2) {
	double dot = 0;
	double elem1;
	double elem2;
	double elemdot;

	for (int i = 0; i < 3; i++) {
		v1.push_back(i);
		elem1 = v1.at(i);
		v2.push_back(i);
		elem2 = v2.at(i);
		elemdot = elem1 * elem2;
		dot += elemdot;
	}
	return dot;
}
void crossArray(double a [], double b [], double out[]) {
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			out[i] = a[i+1] * b[i+2] - a[i+2] * b[i+1];
		}
		if (i == 1) {
			out[i] = a[i+1] * b[i-1] - a[i-1] * b[i+1];
		}
		if(i == 2) {
			out[i] = a[i-2] * b[i-1] - a[i-1] * b[i-2];
		}
	}
}
vector<double> crossVector(vector<double> v1, vector<double> v2) {
	vector<double> cross;
	double i1, j1, k1, i2, j2, k2;
	v1.push_back(0);
	v1.push_back(1);
	v1.push_back(2);
	v2.push_back(0);
	v2.push_back(1);
	v2.push_back(2);
	i1  = v1.at(0);
	i2 = v2.at(0);
	j1 = v1.at(1);
	j2 = v2.at(1);
	k1 = v1.at(2);
	k2 = v2.at(2);
	cross.push_back(0);
	cross.push_back(1);
	cross.push_back(2);
	cross.at(0) = j1 * k2 - k1 * j2;
	cross.at(1) = k1 * i2 - k2 * i1;
	cross.at(2) = i1 * j2 - i2 * j1;
	return cross;
}

