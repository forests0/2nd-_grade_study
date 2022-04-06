#include <iostream>
using namespace std;

#define ID_LEN 20
#define MAX_spd 200
#define Fuel_step 2
#define ACC_step 10
#define BRK_step 10


struct Car
{

	char gamerID[ID_LEN];
	int fuelGauge;
	int curSpeed;
    int letitem;
	public :
	void ShowCarState();
    void Accel();
    void Break();
    int AttackCar(Car a, Car b);
};

void Car::ShowCarState()
{
	cout << "유저ID : " << gamerID << endl;
	cout << "연료량 : " << fuelGauge << endl;
	cout << "현재속도 : " << curSpeed << endl;
    cout<< "남은 아이템양 : " << letitem << endl;
}

void Car::Accel() {
    if(fuelGauge <= 0) {
        return;
    }
    else {
        fuelGauge -= Fuel_step;
    }
    if(curSpeed + ACC_step >= MAX_spd) {
        curSpeed = MAX_spd;
        return;
    }
    curSpeed += ACC_step;
}

void Car::Break() {
    if(curSpeed <= BRK_step) {
        curSpeed = 0;
        return;
    }
    curSpeed -= BRK_step;
}


int AttackCar(Car a, Car b) {
    
}

int main() {
    Car car1 = {"Hello", 100, 0, 10};


    car1.Accel();
    car1.Break();
    car1.ShowCarState();
}