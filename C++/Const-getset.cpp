#include <iostream>
using namespace std;

class Point
{
private:
	float x;
	float y;
	
public:
	float GetX() const
	{
		return x;
	}
	
	float GetY() const
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
	void ShowPosition() const
	{
		cout << "[" << GetX() << ", " << GetY() << "]" << endl;
	}
};

int main(void)
{
	Point p;
	if(p.InitMembers(2, 4))
		p.ShowPosition();
	return 0;
}