#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x, int y): xpos(x), ypos(y) {}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point operator+(const Point& src)
	{
		cout << "member" << endl;
		Point p(xpos+src.xpos, ypos+src.ypos);
		return p;
	}
	friend Point operator+(const Point&, const Point&);
    friend Point operator-(const Point&, const Point&);

    Point operator+=(const Point& src ) {
        Point p(xpos += src.xpos, ypos += src.ypos);
        return *this;
    }

    Point operator-=(const Point& src ) {
        Point p(xpos -= src.xpos, ypos -= src.ypos);
        return *this;
    }
    Point operator*(const int& k ) {
        Point p(xpos * k, ypos * k);
        return *this;
    }
    Point operator*(const Point& src ) {
        Point p(xpos * src.xpos, ypos * src.ypos);
        return *this;
    }
    friend bool operator==(const Point&, const Point&);
    friend bool operator!=(const Point&, const Point&);
    friend Point operator*(const int&, const Point&);
};

Point operator+(const Point& p1, const Point& p2)
{
	cout << "global" << endl;
	Point p(p1.xpos+p2.xpos, p1.ypos+p2.ypos);
	return p;
}

Point operator-(const Point& p1, const Point& p2) {
    Point p(p1.xpos - p2.xpos, p1.ypos - p2.ypos);
    return p;
}

bool operator==(const Point& p1, const Point& p2) {
    return p1.xpos == p2.xpos && p1.ypos == p2.ypos;
}

bool operator!=(const Point& p1, const Point& p2) {
    return !(p1==p2);
}

Point operator*(const int& k, const Point& src) {
    Point p(k * src.xpos, k * src.ypos);
    return p;
}

int main(void)
{
    Point p1(1, 2);
    Point p2(3, 4);
    
    Point p3 = p1*p2;
    p3.ShowPosition();
    
    Point p4 = p1*5;
    p4.ShowPosition();
    
    Point p5 = 5*p1;
    p5.ShowPosition();
    
    if(p4==p5)
        cout << "p4 == p5" << endl;
    if(p4!=p5)
        cout << "p4 != p5" << endl;
    
    return 0;   
}