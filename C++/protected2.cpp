#include <iostream>
using namespace std;

class Base
{
private:
	int num1;
protected:
	int num2;
public:
	int num3;
public:
	Base(): num1(1), num2(2), num3(3) {}
};

class Derived: public Base
{
public:
	void ShowBaseMember() const
	{
		//cout << num1 << endl;
		cout << num2 << endl;
		cout << num3 << endl;
	}
};

int main(void)
{
	Derived obj;
	obj.ShowBaseMember();
	return 0;
}