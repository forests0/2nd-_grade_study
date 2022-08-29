#include <iostream>
using namespace std;

template <typename T>
T Add(T num1, T num2) {
	return num1 + num2;
}

template <typename T, typename Y>
Y ADD(T num1, Y num2) {
    return num1 + num2;
}

int main(void) {
	cout << ADD(1, 2.2) << endl;
	return 0;
}