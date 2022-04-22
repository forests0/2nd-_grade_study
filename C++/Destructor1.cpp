#include <cstring>
#include <iostream>
using namespace std;

class Person
{
private:
	char *name;
	int age;

public:
	Person(char *myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		cout << name << " called destructor" << endl;
		delete[] name;
	}
};

int main(void)
{
	Person* student = new Person("Kim", 18);
	student->ShowPersonInfo();
	
	Person student2 = *student;
	student2.ShowPersonInfo();
	
	delete student;
	student2.ShowPersonInfo();

    Person p1("Kim", 18);
	Person p2("Lee", 19);
	p1.ShowPersonInfo();
	p2.ShowPersonInfo();
	return 0;
}