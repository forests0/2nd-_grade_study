#include <iostream>
#include <cstring>
using namespace std;

class First
{
private:
	char* strFirst;
public:
	First(char* str)
	{
		strFirst = new char[strlen(str)+1];
		strcpy(strFirst, str);
	}
	virtual ~First()
	{
		cout << "~First()" << endl;
		delete[] strFirst;
	}
};

class Second: public First
{
private:
	char* strSecond;
public:
	Second(char* str1, char* str2): First(str1)
	{
		strSecond = new char[strlen(str2)+1];
		strcpy(strSecond, str2);
	}
	virtual ~Second()
	{
		cout << "~Second()" << endl;
		delete[] strSecond;
	}
};

int main(void)
{
	First* ptr = new Second("First", "Second");
	delete ptr;

	return 0;
}