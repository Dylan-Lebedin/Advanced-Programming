#include "VoltageSupply.h"
using namespace std;


VoltageSupply::VoltageSupply(double newVoltage)
{
	voltage = newVoltage;
}

VoltageSupply::VoltageSupply()
{
}

double VoltageSupply::getVoltage() {
	return voltage;
}

void VoltageSupply::setVoltage(double newVoltage) {
	voltage = newVoltage;
}

VoltageSupply::~VoltageSupply()
{
}
