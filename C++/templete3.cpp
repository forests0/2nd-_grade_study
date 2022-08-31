#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T Max(T a, T b) {
	cout << "T Max(T, T)" << endl;
	return a > b ? a : b;
}

template <>
const char* Max(const char* a, const char* b) {
	cout << "const char* Max(const char*, const char*)" << endl;
	return strcmp(a, b) ? a : b;
}

template <>
char* Max(char* a, char* b) {
	cout << "char* Max(char*, char*)" << endl;
	return strcmp(a, b) ? a : b;
}

int main(void) {
	cout << Max(10, 20) << endl;
	cout << Max('T', 'Q') << endl;
	cout << Max(3.5, 7.5) << endl;
	cout << Max("BCDE", "ABC") << endl;
	return 0;
}