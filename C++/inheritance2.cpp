#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
	char name[100];
public:
	Employee(char* name)
	{
		strcpy(this->name, name);
	}
	void ShowEmployeeInfo() const
	{
		cout << "이름: " << name << endl;
	}
};

class FullTimeWorker : public Employee
{
private:
	int salary;
public:
	FullTimeWorker(char* name, int salary): Employee(name), salary(salary) {}
	int GetPay() const
	{
		return salary;
	}
	void ShowFullTimeWorkerInfo() const
	{
		ShowEmployeeInfo();
		cout << "급여: " << salary << endl;
	}
};

int main(void){
	FullTimeWorker ftw("KIM", 100000);
	ftw.ShowFullTimeWorkerInfo();
	return 0;
}