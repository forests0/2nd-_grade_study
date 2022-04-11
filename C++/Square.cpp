#include <iostream>
using namespace std;

class Point
{
private:
	float x, y;
public:
	void InitMembers(float xpos, float ypos)
	{
		SetX(xpos); SetY(ypos);
	}
	void Move(float xNum, float yNum)
	{
		x += xNum;
		y += yNum;
	}
	float GetX() const { return x; }
	float GetY() const { return y; }
	void SetX(float xpos) { x = xpos; }
	void SetY(float ypos) { y = ypos; }
	void ShowPosition() const
	{
		cout << "[" << GetX() << ", " << GetY() << "]" << endl;
	}
};

class Rectangle
{
private:
	Point upLeft;
	Point lowRight;
public:
	void InitMembers(const Point& p1, const Point& p2)
	{
		upLeft = p1;
		lowRight = p2;
	}
	
	void TranslationUpLeft(float xNum, float yNum)
	{
		upLeft.Move(xNum, yNum);
	}
	
	void TranslationLowRight(float xNum, float yNum)
	{
		lowRight.Move(xNum, yNum);
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
	Point p1, p2;
	p1.InitMembers(10, 10);
	p2.InitMembers(20, 30);

	Rectangle rec;
	rec.InitMembers(p1, p2);
	rec.ShowRecInfo();
	
	rec.TranslationUpLeft(5, 5);
	rec.TranslationLowRight(5, 5);
	rec.ShowRecInfo();
	return 0;
}