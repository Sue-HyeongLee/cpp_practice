#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Car {
private:
	int gasolineGauge;
public:
	Car(int gas) :
		gasolineGauge(gas){

	}
	int GetGasGauge() {
		return gasolineGauge;
	}
};

class HybridCar : public Car
{
private:
	int electricGauge;
public:
	HybridCar(int elec, int gas)
	: Car(gas), electricGauge(elec)
	{

	}
	int GetElecGauge() {
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar {
private:
	int WaterGauge;
public:
	HybridWaterCar(int water, int elec, int gas)
	: HybridCar(elec, gas), WaterGauge(water)
	{

	}
	void ShowCurrentGauge() {
		cout << "ÀÜ¿© °¡¼Ö¸°: " << GetGasGauge() << endl;
		cout << "ÀÜ¿© Àü±â·®: " << GetElecGauge() << endl;
		cout << "ÀÜ¿© ¿öÅÍ·®: " << WaterGauge << endl;
	}
};

int main(void) {
	
	HybridWaterCar car(3, 5, 7);
	car.ShowCurrentGauge();
}