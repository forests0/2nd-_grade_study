#include <iostream>
using namespace std;

class First
{
public:
    virtual void MyFunc() { cout << "FirstFunc" << endl; }
};

class Second: public First
{
public:
    virtual void MyFunc() { cout << "SecondFunc" << endl; }
};

class Third: public Second
{
public:
    virtual void MyFunc() { cout << "ThirdFunc" << endl; }
};

int main(void)
{
    Third* tPtr = new Third();
    Second* sPtr = tPtr;
    First* fPtr = sPtr;
    
    fPtr->MyFunc();
    sPtr->MyFunc();
    tPtr->MyFunc();
    delete tPtr;
    return 0;
}