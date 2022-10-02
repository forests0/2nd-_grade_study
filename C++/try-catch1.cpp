#include <iostream>
using namespace std;

int main() {
    int dividend, divisor;
    cout << "정수 입력 : ";
    cin >> dividend >> divisor;
    try {
        if(divisor == 0) throw divisor;
		cout << "몫: " << dividend / divisor << endl;
		cout << "나머지: " << dividend % divisor << endl;    
    } 
    catch(int exception) {
        cout<<"제수는 " << divisor << "이 될 수 없습니다." << endl;
        cout<< "프로그램이 종료됩니다" << endl;
    }
    return 0;
}

