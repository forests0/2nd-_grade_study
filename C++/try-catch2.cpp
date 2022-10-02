#include <iostream>
using namespace std;

void Divide(int dividend, int divisor) {
	if(divisor==0)
		throw divisor;
	cout << "몫: " << dividend / divisor << endl;
	cout << "나머지: " << dividend % divisor << endl;
}

int main() {
	int dividend, divisor;
	cout << "두 정수 입력: ";
	cin >> dividend >> divisor;
	try {
		Divide(dividend, divisor);
	}
	catch(int expn) {
		cout << "제수는 " << expn << "이 될 수 없습니다." << endl;
		cout << "프로그램이 종료됩니다." << endl;
	}
	return 0;
}