#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
    void ShowPositon() const
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
    friend ostream &operator<<(ostream &os, const Point &p);
};

ostream &operator<<(ostream &os, const Point &p)
{
    cout << "[" << p.xpos << "," << p.ypos << "]";
    return os;
}