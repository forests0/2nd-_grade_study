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
	friend Point AddGlobalFunc(const Point&, const Point&);
};

Point AddGlobalFunc(const Point& p1, const Point& p2)
{
	Point p(p1.xpos+p2.xpos, p1.ypos+p2.ypos);
	return p;
}

int main(void)
{
	Point p1(1, 2);
	Point p2(3, 4);
	Point p3 = AddGlobalFunc(p1, p2);
	p3.ShowPosition();
	return 0;
}