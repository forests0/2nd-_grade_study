#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
    char name[100];
    int salary;

public:
    Employee(char *name, int salary) : salary(salary)
    {
        strcpy(this->name, name);
    }
    int GetPay() const
    {
        return salary;
    }
    void ShowEmployeeInfo() const
    {
        cout << "name: " << name << endl;
        cout << "salary: " << salary << endl
             << endl;
    }
};

class EmployeeHandler
{
private:
    Employee *empList[100];
    int empNum;
    int j;

public:
    EmployeeHandler() : empNum(0) {}
    void AddEmployee(Employee *emp)
    {
        empList[empNum] = emp;
        empNum++;
    }
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
        {
            empList[i]->ShowEmployeeInfo();
        }
    }
    void ShowTotalSalary() const
    {
        int totalSalary = 0;
        for (int i = 0; i < empNum; i++)
        {
            totalSalary += empList[empNum]->GetPay();
        }
        cout << totalSalary << endl;
    }
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
        {
            delete empList;
        }
    }
};

int main()
{
    EmployeeHandler handler;
    handler.AddEmployee(new Employee("KIM", 1000));
    handler.AddEmployee(new Employee("Lee", 2000));
    handler.AddEmployee(new Employee("PARK", 140));

    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();
}