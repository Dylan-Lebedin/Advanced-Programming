#include <iostream>
#pragma once
using namespace std;
class VoltageSupply {

private:
	double voltage;

public:
	double getVoltage();
	void setVoltage(double newVoltage);
	VoltageSupply(double);
	VoltageSupply();
	~VoltageSupply();
};

