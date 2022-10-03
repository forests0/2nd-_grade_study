#include <iostream>
using namespace std;

int main(void) {
	int num;
	cin >> num;
	try {
		if(num==0) throw '0';
		else throw -1;
	}
	catch(char expn) {
		cout << "catch(char) " << expn << endl;
	}
	catch(int expn) {
		cout << "catch(int) " << expn << endl;
	}
	return 0;
}