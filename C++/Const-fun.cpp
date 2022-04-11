#include <iostream>
using namespace std;

class Number
{
private:
	float num;
	
public:
	float GetNum() const
	{
		return num;
	}
	void SetNum(float n)
	{
		num = n;
	}
};

class Point
{
private:
	float x;
	float y;

public:
	void InitMembers(const Number& xNum, const Number& yNum)
	{
		x = xNum.GetNum();
		y = yNum.GetNum();
	}
    void ShowPosition() {

    }
};

int main(void)
{
	Number x, y;
	x.SetNum(2);
	y.SetNum(4);

	Point p;
	p.InitMembers(x, y);
	p.ShowPosition();

	return 0;
}