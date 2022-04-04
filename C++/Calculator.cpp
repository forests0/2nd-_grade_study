#include <iostream>
using namespace std;

class Calculator
{
private:
    float x;
    float y;
    float a;
    int count1;
    int count2;
    int count3;
    int count4;

public:
    float Add(float x, float y);
    float Div(float x, float y);
    float Min(float x, float y);
    float Tim(float x, float y);
    void ShowopCount();
    void init();
};

float Calculator::Add(float x, float y)
{
    return x + y;
    count1++;
}
float Calculator::Min(float x, float y)
{
    return x - y;
    count2++;
}
float Calculator::Div(float x, float y)
{
    return x / y;
    count3++;
}
float Calculator::Tim(float x, float y)
{
    return x * y;
    count4++;
}

void Calculator::ShowopCount()
{
    cout << "덧셈 : " << count1 << " 뺄셈 : " << count2 << " 곱셈 : " << count4 << " 나눗셈 : " << count3 << endl;
}

void Calculator::init()
{
    x = 0;
    y = 0;
    a = 0;
}
int main()
{
    Calculator cal;
    cal.init();
    cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
    cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
    cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
    cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
    cal.ShowopCount();
    return 0;
}
