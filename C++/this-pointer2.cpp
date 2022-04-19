#include <iostream>
using namespace std;

class Simpleclass {
    private :
    int num;
    public :
    Simpleclass(int n) : num(n) {}
    Simpleclass Adder(int n) {
        num += n;
        return *this;
    }
    Simpleclass ShowData() {
        cout<<num<<endl;
        return *this;
    }
};

int main() {
    Simpleclass sc1(100);
    Simpleclass sc2 = sc1.Adder(100);
    Simpleclass sc3 = sc1.Adder(100);

    sc1.ShowData();
    sc2.ShowData();
    sc3.ShowData();

    sc1.Adder(1);
    sc1.ShowData();
    sc3.ShowData();


}