#include <iostream>
using namespace std;

class Point
{
private:
	float x, y;
public:
	Point(const float& xpos, const float& ypos)
	{
		x = xpos;
		y = ypos;
	}
	void ShowPosition() const
	{
		cout << "[" << x << ", " << y << "]" << endl;
	}
};

class Rectangle
{
private:
	Point upLeft, lowRight;
public:
	Rectangle(const float& x1, const float& y1, const float& x2, const float& y2) : upLeft(x1, y1), lowRight(x2,y2)
	{
		
	}
	
	void ShowRecInfo() const
	{
		cout << "좌 상단: ";
		upLeft.ShowPosition();
		cout << "우 하단: ";
		lowRight.ShowPosition();
	}
};

int main(void)
{
	Rectangle rec(1, 1, 5, 5);
	rec.ShowRecInfo();
	return 0;
}