#include <cstring>
#include <iostream>
using namespace std;

class Person {
    private :
    char *name;
    int age;
    public :
    Person(char *n, int a) {
        int len = strlen(n) + 1;
        name = new char[len];
        strcpy(name, n);
        age = a;
    }
    void ShowPersonInfo() const {
        cout<<"이름 : "<<name<<endl;
        cout<<"나이 : "<<age<<endl;
    }
    ~Person() {
        cout<<name<<" called Destructor"<<endl;
        delete[] name;
    }
};

int main() {
    char namestr[1000];
    int age;
    Person* person[3];
    for(int i = 0; i < 3; i++) {
        cout<<"이름 : ";
        cin>>namestr;
        cout<<"나이 : ";
        cin>>age;
        person[i] = new Person(namestr, age);
    }
    for(int i = 0; i < 3; i++) {
        person[i]->ShowPersonInfo();
    }
    for(int i = 0; i < 3; i++) {
        delete person[i];
    }
}