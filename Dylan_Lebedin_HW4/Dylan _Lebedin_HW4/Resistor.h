#include <iostream>
#pragma once
using namespace std;
class Resistor {
private:
	double resistor;

public:
	double getResistance();
	void setResistance(double newResistance);
	Resistor();
	Resistor(double);
	~Resistor();
};

