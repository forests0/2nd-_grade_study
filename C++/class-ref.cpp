#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num, num2;
public:
	SimpleClass(int n = 0, int n1 = 0)
	{
		num = n;
        n1 = 0;
	}
	int GetNum() const
	{
		return num;
	}
};