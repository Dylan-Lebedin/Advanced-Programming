#include "Circuit.h"
#include "Resistor.h"
#include "Diode.h"
#include "VoltageSupply.h"
Circuit:: Circuit() {
	resistor =  Resistor(1000);
	voltage = VoltageSupply(2.0);
	Diode diode = Diode(2.6e-15, 26e-3, 1.0);
}

Circuit::Circuit(VoltageSupply newVoltage, Resistor newResistor, Diode newDiode) {
	newResistor = resistor.getResistance();
	newVoltage = voltage.getVoltage();
	newDiode =  Diode(diode.getSatCurrent(), diode.getThermalVoltage(), diode.getIdeality());
}

double Circuit::getVoltageSupply() {
	return voltage.getVoltage();
}

void Circuit::setVoltageSupply(double newVoltageSupply) {
	voltage.setVoltage(newVoltageSupply);
}

double Circuit::getResistor() {
	return resistor.getResistance();
}
void Circuit::setResistor(double newResistor) {
	resistor.setResistance(newResistor);
}
Diode Circuit::getDiode() {
	return diode;
}
void Circuit::setDiode(double newSatCurrent, double newThermalVoltage, double newIdeality) {
	diode.setSatCurrent(newSatCurrent);
	diode.setThermalVoltage(newThermalVoltage);
	diode.setIdeality(newIdeality);
}

Circuit::~Circuit()
{
}
