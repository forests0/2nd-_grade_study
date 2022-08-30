#include <iostream>
using namespace std;

class Point {
    private :
    int xpos, ypos;
    public :
    Point(int num1,int num2) : xpos(num1), ypos(num2) {}
    Point operator+(const Point& p) {
        Point res(xpos + p.xpos, ypos + p.ypos);
        return res;
    }
    friend ostream& operator<<(ostream&, const Point&);
};

ostream& operator<<(ostream& os, const Point& p)
{
	os << '[' << p.xpos << ", " << p.ypos << ']' << endl;
	return os;
}

template <typename T>
T Add(T num1, T num2) {
    return num1 + num2;
}

int main() {

    cout << Add(Point(1,2),Point(3,4)) << endl;
}