#include <iostream>
using namespace std;

class AAA {
    public :
    AAA() {
        cout<<"I'm empty class"<<endl;
    }
    void show() const {
        cout<<"I'm class AAA"<<endl;
    }
};

class BBB {
    AAA& ref;
    const int num;
    const int& refnum;

    public :
    BBB(AAA& r, const int& n1, const int& n2) : ref(r), num(n1), refnum(n2) {
        cout<<"Genergate BBB"<<endl;
    }
    void show() {
        cout<<"and"<<endl;
        cout<<"My refnum : "<<refnum<<endl;
        cout<<"and"<<endl;
        cout<<"My const num : "<<num <<endl;
    }
};

int main() {
    AAA ob1;
    BBB ob2(ob1, 10 , 20);
    ob2.show();
    return 0;
}