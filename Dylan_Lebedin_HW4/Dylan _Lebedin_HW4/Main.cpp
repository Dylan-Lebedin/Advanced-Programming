#include <iostream>
#include "Circuit.h"
#include "Resistor.h"
#include "Diode.h"
#include "VoltageSupply.h"
#include <math.h>
using namespace std;

double DiodeVoltage(double voltageSupply, double resistor, double satCurrent, double thermalVoltage, double ideality, double VD_prev){
	double VD;
	VD = ((voltageSupply - VD_prev) / resistor) - satCurrent * (exp(VD_prev / (ideality*thermalVoltage)) - 1);
	return VD;
}

double DiodeVoltagePrime(double voltageSupply, double resistor, double satCurrent, double thermalVoltage, double ideality, double VD_prev) {
	double VDprime;
	VDprime = -(1 / resistor) - (satCurrent / (ideality * thermalVoltage)) * exp(VD_prev / (ideality * thermalVoltage));
	return VDprime;
}


double NewtonRaphson(double voltageSupply, double resistor, double satCurrent,  double thermalVoltage, double ideality, double VD_prev) {
	double VD;
	double VDPr;
	double x;
	static int i = 0;
	VD = DiodeVoltage(voltageSupply, resistor, satCurrent, thermalVoltage, ideality, VD_prev);
	VDPr = DiodeVoltagePrime(voltageSupply, resistor, satCurrent, thermalVoltage, ideality, VD_prev);
	x = VD_prev - (VD / VDPr);
	if (abs(VD_prev - x) < 0.0000001) {

		return x;
	}
	else {
		i++;
		return NewtonRaphson(voltageSupply, resistor, satCurrent, thermalVoltage, ideality, x);
	}
}

int main() {

	double guess1;
	double resistor_default;
	double voltage_default;
	double satCurrent_default;
	double thermalVoltage_default;
	double ideality_default;

	Circuit circuit = Circuit();
	cout << "Circuit elements in the default circuit have the following properties:" << endl;
	resistor_default = circuit.getResistor();
	voltage_default = circuit.getVoltageSupply();
	satCurrent_default = circuit.getDiode().getSatCurrent();
	thermalVoltage_default = circuit.getDiode().getThermalVoltage();
	 ideality_default = circuit.getDiode().getIdeality();
	cout << "Resistor resistance: " << resistor_default << endl;
	cout << "Voltage Supply voltage: " << voltage_default<< endl;
	cout << "Diode saturation current " << satCurrent_default << endl;
	cout << "Diode thermal voltage: " << thermalVoltage_default << endl;
	cout << "Diode ideality: " << ideality_default << endl;

	cout << "\nEnter guess for the voltage across the diode for the desired circuit: ";
	cin >> guess1;

	DiodeVoltage(voltage_default, resistor_default, satCurrent_default, thermalVoltage_default, ideality_default, guess1);
	DiodeVoltagePrime(voltage_default, resistor_default, satCurrent_default, thermalVoltage_default, ideality_default, guess1);
	cout << "\nThe voltage drop across the diode is: " << NewtonRaphson(voltage_default, resistor_default, satCurrent_default, thermalVoltage_default, ideality_default, guess1) << endl;
	
	double resistor;
	double voltage;
	double satCurrent;
	double thermalVoltage;
	double ideality;
	double guess2; 
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "\nEnter desired resistor resistance value: ";
	cin >> resistor;
	//cout << resistor << endl;
	cout << "Enter desired voltage supply value: ";
	cin >> voltage;
	cout << "Enter desired diode saturation current value: ";
	cin >> satCurrent;
	cout << "Enter desired diode thermal voltage value: ";
	cin >> thermalVoltage;
	cout << "Enter desired diode ideality value (1<n<2): ";
	cin >> ideality;
	
	//Diode circuit_diode = Diode(satCurrent, thermalVoltage, ideality);
	Circuit circuit1;
	circuit1.setResistor(resistor);
	circuit1.setVoltageSupply(voltage);
	circuit1.setDiode(satCurrent, thermalVoltage, ideality);

	Circuit *ptrCircuit;

	ptrCircuit = &circuit1;

	//double resistor1 = circuit1.getResistor();
	//double voltage1 = circuit1.getVoltageSupply();
	//double satCurrent1 = circuit1.getDiode().getSatCurrent();
	//double thermalVoltage1 = circuit1.getDiode().getThermalVoltage();
	//double ideality1 = circuit1.getDiode().getIdeality();

	double resistor1 = ptrCircuit -> getResistor();
	double voltage1 = ptrCircuit -> getVoltageSupply();
	double satCurrent1 = ptrCircuit -> getDiode().getSatCurrent();
	double thermalVoltage1 = ptrCircuit -> getDiode().getThermalVoltage();
	double ideality1 = ptrCircuit -> getDiode().getIdeality();


	cout << "\n\nCircuit elements created using desired user inputs have the following properties: " << endl;
	cout << "\nResistor resistance: " << resistor1 << endl;
	cout << "Voltage Supply voltage: " << voltage1 << endl;
	cout << "Diode saturation current: " << satCurrent1 << endl;
	cout << "Diode thermal voltage: " << thermalVoltage1 << endl;
	cout << "Diode ideality: " << ideality1 << endl;

	cout << "\nEnter guess for the voltage across the diode for the desired circuit: ";
	cin >> guess2;

	DiodeVoltage(voltage1, resistor1, satCurrent1, thermalVoltage1, ideality1, guess2);
	DiodeVoltagePrime(voltage1, resistor1, satCurrent1, thermalVoltage1, ideality1, guess2);
	cout << "\nThe voltage drop across the diode is: " << NewtonRaphson(voltage1, resistor1, satCurrent1, thermalVoltage1, ideality1, guess2) << endl << endl;
	system("pause");
	return 0;
}
