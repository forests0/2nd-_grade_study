#include <iostream>
#include <cstring>
using namespace std;

class Printer {
    private :
    string str;
    public :
    string Setstring(string a) {
        str = a;
    }
    void Showstring() {
        cout<<str<<endl;
    }

};

int main() {
    Printer pnt;
    pnt.Setstring("Hello World");
    pnt.Showstring();

    pnt.Setstring("I love C++");
    pnt.Showstring();
    return 0;
}