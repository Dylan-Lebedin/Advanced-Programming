#pragma once
class Diode
{
private:
	double satCurrent;
	double ideality;
	double thermalVoltage;

public:
	double getSatCurrent();
	void setSatCurrent(double newSatCurrent);
	double getIdeality();
	void setIdeality(double newIdeality);
	double getThermalVoltage();
	void setThermalVoltage(double newThermalVoltage);

	Diode();
	Diode(double, double);
	Diode(double, double, double);
	~Diode();
};

