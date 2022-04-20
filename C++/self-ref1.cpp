#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num;
public:
	SimpleClass(int n): num(n) {}
	SimpleClass& Adder(int n)
	{
		num += n;
		return *this;
	}
	SimpleClass& ShowSimpleData()
	{ 
		cout << num << endl;
		return *this;
	}
};

int main(void)
{
	SimpleClass sc(100);
	sc.Adder(1).Adder(2).Adder(3).ShowSimpleData();
	return 0;
}