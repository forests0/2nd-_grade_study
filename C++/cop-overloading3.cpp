#include <iostream>
using namespace std;

class Base
{
private:
	int baseNum;
public:
	Base(int num=0): baseNum(num) {}
	void ShowData() const { cout << baseNum << endl; }
	Base& operator=(const Base& ref)
	{
		cout << "Base operator=" << endl;
		baseNum = ref.baseNum;
		return *this;
	}
};

class Derived: public Base
{
private:
	int dervNum;
public:
	Derived(int num1, int num2): Base(num1), dervNum(num2) {}
	void ShowData() const
	{
		Base::ShowData();
		cout << dervNum << endl;
	}
	Derived& operator=(const Derived& ref)
	{
		cout << "Derived operator=" << endl;
        Base::operator=(ref);
		dervNum = ref.dervNum;
		return *this;
	}
};

int main(void)
{
	Derived obj1(111, 222);
	Derived obj2(0, 0);
	obj2 = obj1;
	obj2.ShowData();
	return 0;
}

