#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num;
public:
	SimpleClass(int num) : num(num) {}
    SimpleClass(SimpleClass& sc) : num(sc.num) {}
	void ShowSimpleData() const { cout << num << endl; }
};

int main(void)
{
	SimpleClass sc1(100);
	SimpleClass sc2 = sc1;
	sc1.ShowSimpleData();
	sc2.ShowSimpleData();
	return 0;
}