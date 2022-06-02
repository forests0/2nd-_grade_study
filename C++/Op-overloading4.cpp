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
    // Point& operator++() {
    //     xpos+= 1;
    //     ypos+= 1;
    //     return *this;
    // }
    // Point& operator--() {
    //     xpos-= 1;
    //     ypos-= 1;
    //     return *this;
    // }
    Point operator-() {
        Point p(-xpos, -ypos);
        return p;
    }
    friend Point &operator++(Point &);
    friend Point &operator--(Point &);
    friend Point operator~(Point &);
};

Point operator~(const Point& p) {
    Point r(p.ypos, p.xpos);
    return r;
}

Point &operator++(Point &p)
{
    p.xpos += 1;
    p.ypos += 1;
    return p;
}

Point &operator--(Point &p)
{
    p.xpos -= 1;
    p.ypos -= 1;
    return p;
}



int main(void)
{
    cout << "전위 증가 연산자" << endl;
    Point p1(1, 2);
    Point &p2 = ++p1;
    p1.ShowPosition();
    p2.ShowPosition();
    ++(++p2);
    p1.ShowPosition();
    p2.ShowPosition();

    cout << endl
         << "전위 감소 연산자" << endl;
    Point p3(11, 22);
    Point &p4 = --p3;
    p3.ShowPosition();
    p4.ShowPosition();
    --(--p4);
    p3.ShowPosition();
    p4.ShowPosition();

    return 0;
}
