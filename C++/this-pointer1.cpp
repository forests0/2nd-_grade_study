#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num;
public:
	SimpleClass(int n): num(n) {}
	void ShowSimpleData() { cout << num << endl; }
	SimpleClass* GetThisPointer() { return this; }
};

int main(void)
{
	SimpleClass sc(100);
	SimpleClass* ptr = sc.GetThisPointer();
	sc.ShowSimpleData();
	ptr->ShowSimpleData();
	if(&sc == ptr)
		cout << "same" << endl;
	else
		cout << "not same" << endl;
	return 0;
}