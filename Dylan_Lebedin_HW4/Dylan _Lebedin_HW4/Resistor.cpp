#include "Resistor.h"
using namespace std;


Resistor::Resistor(double newResistance)
{
	resistor = newResistance;
}

Resistor::Resistor() {

}

double Resistor::getResistance() {
	return resistor;
}
void Resistor::setResistance(double newResistance) {
	resistor = newResistance;
}


Resistor::~Resistor()
{
}
