#include "Diode.h"
#include "Resistor.h"
#include "VoltageSupply.h"
using namespace std;
class Circuit
{

private :
	VoltageSupply voltage;
	Resistor resistor;
	Diode diode;
public:
	double getVoltageSupply();
	void setVoltageSupply(double newVoltageSupply);
	double getResistor();
	void setResistor(double newResistor);
	Diode getDiode();
	void setDiode(double newIdeality, double newSatCurrent, double newThermalVoltage);
	Circuit();
	Circuit(VoltageSupply, Resistor, Diode);
	~Circuit();
};

