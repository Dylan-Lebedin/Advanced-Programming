#include <iostream>
using namespace std;

constexpr auto TRUE = 1;
constexpr auto FALSE = 0;

void printarray(int a[], int a_length);
void sepdigits(long int n);
int digits_different(int a[], int a_length);
int divisible(int a[], int a_length, long int num);

int main()
{
	long int user_input;

	cout << "Enter a positive integer or 0 (zero) to end: ";
	cin >> user_input;

	while (user_input != 0) {
		if (user_input < 0) {
			cout << "Wrong input\n";
		}
		else {
			sepdigits(user_input);
		}
		cout << "\nEnter a positive integer or 0 (zero) to end: ";
		cin >> user_input;
	}
	cout << "\n*** Program Terminated ***";
	return 0;
}

void sepdigits(long int n) {
	int a[10] = { 0 };
	int digit;
	long int num;
	num = n;

	while (num > 0) {
		digit = num % 10;
		++a[digit];
		num = num - digit;
		num = num / 10;
	}
	printarray(a, 10);

	if (a[0] != 0) {
		cout << "\n\nWrong input for the second part.\n";
		cout << "Input should not contain zero.\n";
	}

	else if (digits_different(a, 10) == FALSE) {
		cout << "\n\nWrong input for the second part.\n";
		cout << "Input should not contain each digit more than once.\n";
	}

	else if (divisible(a, 10, n) == FALSE) {
		cout << "\n\n" << n << " is not divisible by its digits.\n";
	}

	else {
		cout << "\n\n" << n << " is divisible by its digits\n";
	}
}

void printarray(int a[], int a_length) {
	cout << "\n\n";
	cout << "Digits:         0  1  2  3  4  5  6  7  8  9\n";
	cout << "Occurences:     ";

	for (int i = 0; i < a_length; i++) {
		cout << a[i] << "  ";
	}
}

int digits_different(int a[], int a_length) {
	for (int i = 0; i < a_length; i++) {
		if (a[i] > 1) {
			return FALSE;
		}
	}
	return TRUE;
}

int divisible(int a[], int a_length, long int num) {
	for (int i = 0; i < a_length; i++) {
		if (a[i] == 0) {
			continue;
		}
		else if (num % i != 0) {
			return FALSE;
		}
	}
	return TRUE;
}
