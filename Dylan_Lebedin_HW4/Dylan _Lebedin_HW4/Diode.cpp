#include "Diode.h"
using namespace std;


Diode::Diode()
{
	satCurrent = 2.6e-15;
	thermalVoltage = 26e-3;
	ideality = 1.0;
}

Diode::Diode(double newSatCurrent, double newThermalVoltage) {
	ideality = 1.0;
	satCurrent = newSatCurrent;
	thermalVoltage = newThermalVoltage;
}

Diode::Diode(double newSatCurrent, double newThermalVoltage, double newIdeality) {
	satCurrent = newSatCurrent;
	thermalVoltage = newThermalVoltage;
	ideality = newIdeality;
}

double Diode::getSatCurrent() {
	return satCurrent;
}
void Diode::setSatCurrent(double newSatCurrent) {
	satCurrent = newSatCurrent;
}
double Diode::getIdeality() {
	return ideality;
}
void Diode::setIdeality(double newIdeality) {
	ideality = newIdeality;
}
double Diode::getThermalVoltage() {
	return thermalVoltage;
}
void Diode::setThermalVoltage(double newThermalVoltage) {
	thermalVoltage = newThermalVoltage;
}
Diode::~Diode()
{
}
