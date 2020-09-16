#include <vector>
#include <iostream>
using namespace std;

void addArray(double a[], double b[], double out [], int dim);
vector<double> addVector(vector<double> v1, vector<double> v2);
void subArray(double a[], double b[], double out[], int dim);
vector<double> subVector(vector<double> v1, vector<double> v2);
double magArray(double a[], double out[], int dim);
double magVector(vector<double> v1);

double dotArray(double a[], double b[], int dim);
double dotVector(vector<double> v1, vector<double> v2);
void crossArray(double a[], double b[], double out[]);
vector<double> crossVector(vector<double> v1, vector<double> v2);


