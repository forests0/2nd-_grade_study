#include <iostream>
using namespace std;

void SwapByRef2(int &ref1, int& ref2)
{
	int temp=ref1;
	ref1=ref2;
	ref2=temp;
}

void SwapByRef1(int *ref1, int *ref2)
{
	int temp=*ref1;
	*ref1=*ref2;
	*ref2=temp;
}

void SwapByVal(int ref1, int ref2)
{
	int temp=ref1;
	ref1=ref2;
	ref2=temp;
}
int main(void)
{
	int val1=10;
	int val2=20;

	SwapByVal(val1,val2);
	cout<<val1<<' '<<val2<<endl;

    SwapByRef1(&val1, &val2);
    cout<<val1<<' '<<val2<<endl;

	SwapByRef2(val1, val2);
	cout<<val1<<' '<<val2<<endl;
	return 0;
}