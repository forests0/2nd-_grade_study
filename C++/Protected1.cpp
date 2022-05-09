#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char *name;

public:
    Person(char *name)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    void Printname() const
    {
        cout << "My name is " << name << endl;
    }
    ~Person()
    {
        delete[] name;
    }
};

class UnivStudent : public Person
{
private:
    char *major;

public:
    UnivStudent(char *name, char *major) : Person(name) {
        this->major = new char[strlen(major) + 1];
        strcpy(this->major, major);
    }
    void whoareyou() const
    {
        Printname();
        cout << "My major is " << major << endl;
    }
    ~UnivStudent() {
        delete[] major;
    }
};

int main()
{
    UnivStudent st1("Kim", "Mathematics");
    st1.whoareyou();
    UnivStudent st2("Park", "Computer Engineering");
    st2.whoareyou();
    return 0;
}