
#include <iostream>
#include <cstring>
using namespace std;
namespace RISK_LEVEL
{
    enum
    {
        RISK_A = 30,
        RISK_B = 20,
        RISK_C = 10,
    };
}

class Employee
{
private:
    char name[100];

public:
    Employee(char *name) { strcpy(this->name, name); }
    void ShowYourName() const { cout << "name: " << name << endl; }
    virtual int GetPay() const {}
    virtual void ShowSalaryInfo() const {}
};
class FullTimeWorker : public Employee
{
private:
    int salary;

public:
    FullTimeWorker(char *name, int salary) : Employee(name), salary(salary) {}
    virtual int GetPay() const { return salary; }
    virtual void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl;
    }
};

class EmployeeHandler
{
private:
    Employee *empList[50];
    int empNum;

public:
    EmployeeHandler() : empNum(0) {}
    void AddEmployee(Employee *emp) { empList[empNum++] = emp; }
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }
    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
        cout << "salary sum: " << sum << endl;
    }
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

class PartTimeWorker : public Employee
{
private:
    int payToHour;
    int workTime;

public:
    PartTimeWorker(char *name, int payToHour)
        : Employee(name), payToHour(payToHour), workTime(0) {}
    virtual int GetPay() const
    {
        return payToHour * workTime;
    }
    virtual void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl;
    }
    void AddWorkTime(int time)
    {
        workTime += time;
    }
};

class SalesWorker : public FullTimeWorker
{
private:
    double inratio;
    int salesresult;

public:
    SalesWorker(char *name, int money, double ratio) : FullTimeWorker(name, money), inratio(ratio), salesresult(0) {}
    virtual int GetPay() const
    {
        return FullTimeWorker::GetPay() + (inratio * salesresult);
    }
    void AddSalesResult(int sresult)
    {
        salesresult += sresult;
    }
    virtual void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl;
    }
};

class ForeignSalesWorker : public SalesWorker
{
private:
    const int Risklevel;

public:
    ForeignSalesWorker(char *name, int money, double ratio, int risklevel) : SalesWorker(name, money, ratio), Risklevel(risklevel) {}
    int GetRiskPay() const { 
         return Risklevel * SalesWorker::GetPay() / 100;
    }
    virtual int GetPay() const
    {
       
        return SalesWorker::GetPay() + GetRiskPay();
    }
    virtual void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << SalesWorker::GetPay() << endl;
        cout << "risk pay : " << GetRiskPay() << endl;
        cout << "total pay : " << GetPay() << endl;
        cout << endl;
    }

};

int main(void)
{
    EmployeeHandler handler;

    ForeignSalesWorker *fsw1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fsw1->AddSalesResult(7000);
    handler.AddEmployee(fsw1);

    ForeignSalesWorker *fsw2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
    fsw2->AddSalesResult(7000);
    handler.AddEmployee(fsw2);

    ForeignSalesWorker *fsw3 = new ForeignSalesWorker("Park", 1000, 0.1, RISK_LEVEL::RISK_C);
    fsw3->AddSalesResult(7000);
    handler.AddEmployee(fsw3);

    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();

    return 0;
}