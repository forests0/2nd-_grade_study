#include <iostream>
using namespace std;

struct point
{
    int xpos;
    int ypos;

    void Movepos(int x, int y)
    {
        xpos += x;
        ypos += y;
    }
    void Addpoint(const point &pos)
    {
        xpos += pos.xpos;
        ypos += pos.ypos;
    }
    void ShowPosition()
    {
        cout << "[" << xpos << "," << ypos << "]" << endl;
    }
};

int main()
{
    point pos1 = {12, 4};
    point pos2 = {20, 30};

    pos1.Movepos(-7, 10);
    pos1.ShowPosition();

    pos1.Addpoint(pos2);
    pos1.ShowPosition();
}