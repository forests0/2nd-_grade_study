#include <iostream>
using namespace std;

class Point
{
    float xpos, ypos;

public:
    void Init(float x, float y)
    {
        xpos = x;
        ypos = y;
    }
    void ShowPInfo() const
    {
        cout << "[" << xpos << "," << ypos << "]" << endl;
    }
};

class Ring
{
    float len, len2;
    Point ipo, opo;

public:
    void Init(float x, float y, float l, float x2, float y2, float l2)
    {
        ipo.Init(x, y);
        len = l;
        opo.Init(x2, y2);
        len2 = l2;
    }
    void ShowRInfo()
    {
        cout << "Inner Circle Info..." << endl;
        cout << "반지름 : " << len << endl;
        ipo.ShowPInfo();

        cout << "Outter Circle Info..." << endl;
        cout << "반지름 : " << len2 << endl;
        opo.ShowPInfo();
    }
};

int main()
{
    Ring ring;
    ring.Init(1, 1, 4, 2, 2, 9);
    ring.ShowRInfo();
    return 0;
}