#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Point {
private:
	T xpos, ypos;
public:
	Point(T xpos=0, T ypos=0): xpos(xpos), ypos(ypos) {}
	Point operator+(const Point& p) {
		Point res(xpos + p.xpos, ypos + p.ypos);
		return res;
	}
	template <typename U>
	friend ostream& operator<<(ostream&, const Point<U>&);
};

template <typename T>
ostream& operator<<(ostream& os, const Point<T>& p) {
		os << "[" << p.xpos << ", " << p.ypos << "]";
		return os; 
}

template <>
class Point<char *> {
    private :
        char* xpos;
        char* ypos;
    public :
        Point(char * xpos, char * ypos) {
            this->xpos = new char[strlen(xpos)+1];
		    strcpy(this->xpos, xpos);

            this->ypos = new char[strlen(ypos)+1];
		    strcpy(this->ypos, ypos);
        }
	Point<char*> operator+(const Point<char*> & p) {
		int xlen = strlen(xpos) + strlen(p.xpos);
        int ylen = strlen(ypos) + strlen(p.ypos);

        char* newx = new char[xlen];
        char* newy = new char[ylen];

        strcpy(newx, xpos);
        strcpy(newy, ypos);

        strcat(newx, p.xpos);
        strcat(newy, p.ypos);

        Point<char*> res(newx, newy);
        delete[] newx;
        delete[] newy;

        return res;
	}
    ~Point() {
        delete[] xpos;
        delete[] ypos;
    }
    template <typename U>
    friend ostream& operator<<(ostream&, const Point<U>&);
};

template <typename T>
ostream& operator<<(ostream& os, const Point<T>& p) {
		os << "[" << p.xpos << ", " << p.ypos << "]";
		return os; 
}

int main(void) {
	Point<int> pInt1(1, 2);
	Point<int> pInt2(3, 4);
	cout << pInt1 + pInt2 << endl;
	
	Point<float> pFloat1(1.1, 2.2);
	Point<float> pFloat2(3.3, 4.4);
	cout << pFloat1 + pFloat2 << endl;

	char str1[] = "AA";
	char str2[] = "BB";
	char str3[] = "CC";
	char str4[] = "DD";
	
	Point<char*> pStr1(str1, str2);
	Point<char*> pStr2(str3, str4);
	cout << pStr1 + pStr2 << endl;

	return 0;
}