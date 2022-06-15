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
	friend ostream& operator<<(ostream&, const Point&);
    friend istream& operator>>(ostream&, Point&);
};

ostream& operator<<(ostream& os, const Point& p)
{
	os << '[' << p.xpos << ", " << p.ypos << ']' << endl;
	return os;
}

// istream& operator>>(istream& is, Point& p) {
//     is >> p.xpos >> p.ypos;
//     return is;
// }

int main(void)
{
	Point p;
	p.ShowPosition();
	cout << p << endl;
	return 0;
}