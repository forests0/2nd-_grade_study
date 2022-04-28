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
    Person(const Person& p) : age(p.age) {
        name = new char[strlen(name) + 1];
        strcpy(name, p.name);
    }
    void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		cout << name << " 소멸자 호출 " << this << endl;
	}
};

int main() {
    Person man("Kim", 18);
	Person woman = man;
	strcpy(woman.name, "Lee");
	woman.age = 20;

	man.ShowPersonInfo();
	woman.ShowPersonInfo();
}