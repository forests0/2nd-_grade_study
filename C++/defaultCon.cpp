#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:
	SimpleClass() {} // 디폴트 생성자
	int GetNum1() const { return num1; }
	int GetNum2() const { return num2; }
	void SetNum1(int n) { num1 = n; }
	void SetNum2(int n) { num2 = n; }
};

int main(void)
{
	SimpleClass sc;
	return 0;
}