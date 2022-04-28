#include <iostream>
#include <cstring>
using namespace std;

class Person
{
public:
	char* name;
	int age;

public:
	Person(char* name, int age): age(age)
	{
		this->name = new char[strlen(name)+1];
		strcpy(this->name, name);
		cout << this->name << " 생성자 호출 " << this << endl;
	}

	~Person()
	{
		cout << name << " 소멸자 호출 " << this << endl;
	}
};

char* func()
{
	Person man("Kim", 18);
	cout << (void*)(man.name) << " " << man.name << endl;
	return man.name;
}

int main(void)
{
	char* str = func();
	cout << (void*)str << " " << str << endl;
	
	cout << "end main" << endl;
	return 0;
}