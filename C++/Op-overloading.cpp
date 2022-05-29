#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0): xpos(x), ypos(y) {}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
    Point AddMemberFunc(Point & newp) const {
        Point points(xpos + newp.xpos, ypos + newp.ypos);
        return points;
    };
};

int main() {
    Point p1(1,2);
    Point p2(3,4);
    Point p3 = p1.AddMemberFunc(p2);
    p3.ShowPosition();

    return 0;
}