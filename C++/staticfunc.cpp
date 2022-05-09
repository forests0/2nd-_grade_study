#include <iostream>
using namespace std;

class AAA
{
private:
	static int num1;
	static int num2;
public:
	static void Adder(int num)
	{
		num1 += num;
		num2 += num;
	}
	void PrintInfo() const
	{
		cout << "num1: " << num1 << endl;
		cout << "num2: " << num2 << endl << endl;
	}
};

int AAA::num2 = 0;

int main(void)
{
	AAA a;
	a.Adder(10);
	a.PrintInfo();
	return 0;
}

//결론적으로, static으로 선언된 함수는 static으로 선언된 변수만 사용 가능함