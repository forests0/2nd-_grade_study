#include <iostream>
using namespace std;

template <typename T>
class Point {
private:
	T xpos, ypos;
public:
	Point(T xpos=0, T ypos=0): xpos(xpos), ypos(ypos) {}
	friend ostream& operator<<(ostream& os, const Point& p) {
		os << "[" << p.xpos << ", " << p.ypos << "]";
		return os;
	}
};

int main() {
	Point<int> p1(2, 3);
	Point<double> p2(2.2, 3.2);
	Point<char> p3('A', 'B');
	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;
	return 0;
}