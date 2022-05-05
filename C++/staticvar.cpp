#include <iostream>
using namespace std;

class AAA
{
private:
	static int objCnt;
public:
	AAA()
	{
		objCnt++;
		cout << objCnt << "번째 AAA 객체" << endl;
	}
};
int AAA::objCnt = 0;

class BBB
{
private:
	static int objCnt;
public:
	BBB()
	{
		objCnt++;
		cout << objCnt << "번째 BBB 객체" << endl;
	}
	BBB(const BBB& copy)
	{
		objCnt++;
		cout << objCnt << "번째 BBB 객체" << endl;
	}
};
int BBB::objCnt = 0;

int main(void)
{
	AAA a1;
	AAA a2;
	
	BBB b1;
	BBB b2 = b1;
	BBB();
	return 0;
}


