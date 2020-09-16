/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;


double store_data[10];
double store_it[10];

int counter = 0;
int t_count = 0;

double f1(double input) {
	double x;
	x = pow(input, 2) - 5 * input + 6;
	return x;
}
double f1_prime(double input) {
	double x;
	x = 2 * input - 5;
	return x;
}
double f1_double_prime(double input) {
	input = 2;
	return input;
}
double f2(double input) {
	double x;
	x = cos(2 * input);
	return x;
}
double f2_prime(double input) {
	double x;
	x = -2 * sin(2 * input);
	return x;
}
double f2_double_prime(double input) {
	double x;
	x = -4 * cos(2 * input);
	return x;
}

double HalleyRecursiveA(double x) {
	double y = f1(x);
	double y1 = f1_prime(x);
	double y2 = f1_double_prime(x);
	double x_n = x - (2 * y * y1) / (2 * pow(y1, 2) - y * y2);
		if (x_n - x < 0.0001) {
			return x_n;
		}
		else if (counter % 10 == 0 && counter > 0) {
		        store_data[t_count] = 0;
		        t_count++;
		}
		counter+=1;
		//cout << "\n" << counter << endl;
		HalleyRecursiveA(x_n);
}

 void HalleyIterativeB(double x) {
	double y = f1(x);
	double y1 = f1_prime(x);
	double y2 = f1_double_prime(x);
	double x_n;
	int counter = 0;
	int counter_2 = 0;
	
	x_n = x - (2 * y * y1) / (2 * pow(y1, 2) - y * y2);
// 	cout << x_n - x;
		while ( x_n - x >= 0.0001 && counter <= 100) {
			x = x_n;
			y = f1(x);
			y1 = f1_prime(x);
			y2 = f1_double_prime(x);
			x_n = x - (2 * y * y1) / (2 * pow(y1, 2) - y * y2);
			
			if (counter % 10 == 0 && counter > 0) {
			    //cout << "True";
			    store_it[counter_2] = x_n;
			    counter_2++;
			}
			counter++;
			//cout << "Hey" << counter;
		}
}

double HalleyRecursiveA1(double x) {
	double y = f1(x);
	double y1 = f1_prime(x);
	double y2 = f1_double_prime(x);
	double x_n = x - (2 * y * y1) / (2 * pow(y1, 2) - y * y2);
		if (x_n - x < 0.0001) {
			return x_n;
		}
		else {
		    //x = x_n;
			HalleyRecursiveA1(x_n);
		}
}
double HalleyRecursiveB1(double x) {
	double y = f2(x);
	double y1 = f2_prime(x);
	double y2 = f2_double_prime(x);
	double x_n = x - (2 * y * y1) / (2 * pow(y1, 2) - y * y2);
		if (x_n - x < 0.0001) {
			return x_n;
		}
		else {
		    //x = x_n;
			HalleyRecursiveB1(x_n);
		}
}

double HalleyIterativeA1(double x) {
	double y = f1(x);
	double y1 = f1_prime(x);
	double y2 = f1_double_prime(x);
	double x_n;
	x_n = x - (2 * y * y1) / (2 * pow(y1, 2) - y * y2);
		while ( x_n - x >= 0.0001) {
			x = x_n;
			y = f1(x);
			y1 = f1_prime(x);
			y2 = f1_double_prime(x);
			x_n = x - (2 * y * y1) / (2 * pow(y1, 2) - y * y2);
		}
	return x_n;
}
double HalleyIterativeB1(double x) {
	double y = f2(x);
	double y1 = f2_prime(x);
	double y2 = f2_double_prime(x);
	double x_n;
	x_n = x - (2 * y * y1) / (2 * pow(y1, 2) - y * y2);
		while ( x_n - x >= 0.0001) {
			x = x_n;
			y = f2(x);
			y1 = f2_prime(x);
			y2 = f2_double_prime(x);
			x_n = x - (2 * y * y1) / (2 * pow(y1, 2) - y * y2);
		}
	return x_n;
}


int main() {
	int input;
	cout << "Enter Guess for Equation 1: ";
	cin >> input;
	cout << HalleyRecursiveA1(input) << endl;
	cout << HalleyIterativeA1(input) << endl;

	cout << "Enter Guess for Equation 2: " << input << endl;
	cout << HalleyRecursiveB1(input) << endl;
	cout << HalleyIterativeB1(input) << endl;
	
	cout << "Enter to Continue\n";

	cout << "Recursive\t\tIterative\n";
	cout << "Iters\tRoot\t\tIters\tRoot" << endl;
	
	 HalleyRecursiveA(input);
	 HalleyIterativeB(input);
	 for (int i = 0; i < 10; i+=1) {
	 //cout << "\n" << store_it[i]<< endl;
	 }
		for (int i = 0; i < 10; i+=1) {
		    cout << 10*(i+1) << "\t" << store_data[i] << "\t\t";
			cout << 10*(i+1) << "\t" << store_it[i] << endl;
		}
		return 0;
}



