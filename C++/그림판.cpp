#include <iostream>
#include <cstring>
using namespace std;

class Point
{
    int xpos;
    int ypos;

public:
    bool Initmembers(int x, int y)
    {
        if (x < 0 || y < 0 || x > 100 || y > 100)
        {
            cout << "벗어난 범위의 값 전달" << endl;
            return false;
        }
        xpos = x;
        ypos = y;
        return true;
    }
    void Showposition()
    {
        cout << "[" << xpos << "," << ypos <<"]" << endl;
    }
};

int main()
{
    Point p;
    if (!p.Initmembers(-2, 4))
    {
        cout << "초기화 실패" << endl;
    }
    if (!p.Initmembers(2, 4))
    {
        cout << "초기화 실패" << endl;
    }
    p.Showposition();
}