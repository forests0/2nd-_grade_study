#include <iostream>
using namespace std;

class Point
{
	float x;
	float y;
public:
	float GetX()
	{
		return x;
	}
	
	float GetY()
	{
		return y;
	}
	
	void SetX(float xpos)
	{
		x = xpos;
	}
	
	void SetY(float ypos)
	{
		y = ypos;
	}
	
	bool InitMembers(float xpos, float ypos);
	void ShowPosition();	
};

int main(void)
{
	Point p;
	if(!p.InitMembers(2, 4))
		cout << p.GetX() << ", " << p.GetY() << endl;
	
	p.SetX(-2);
	p.SetY(400);
	cout << p.GetX() << ", " << p.GetY() << endl;
	return 0;
}