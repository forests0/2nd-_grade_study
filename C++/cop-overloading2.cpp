#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(char* name, int age)
	{
		this->name = new char[strlen(name)+1];
		strcpy(this->name, name);
		this->age = age;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete []name;
		cout << "called destructor" << endl;
	}
    Person& operator=(const Person& obj) {
        delete []name;
        this->name = new char[strlen(obj.name)+1];
		strcpy(this->name, obj.name);
		this->age = obj.age;
        return *this;
    }
};

int main(void)
{
	Person man1("Hong gil dong", 20);
	Person man2("Go gil dong", 40);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}