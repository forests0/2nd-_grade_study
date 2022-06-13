#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x, int y) : xpos(x), ypos(y) {}
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    friend Point &operator--(Point &, int);
};

Point &operator--(Point &p, int)
{
    Point r(p.xpos, p.ypos);
    p.xpos--;
    p.ypos--;
    return r;
}

int main() {
    Point p1(1,2);
    const Point p3 = p1--;
    const Point& p4 = p1--;


    p1.ShowPosition();
    p3.ShowPosition();
    p4.ShowPosition();
}