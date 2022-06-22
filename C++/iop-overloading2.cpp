#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0): xpos(x), ypos(y) {}
    friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
    cout << "[" << pos.xpos << ", " << pos.ypos << "]";
    return os;
}

class MyPointArray
{
private:
	Point* arr;
	int len;
	MyPointArray(const MyPointArray& ref) {}
	MyPointArray& operator=(const MyPointArray& ref) {}
public:
	MyPointArray(int len): len(len)
	{
		arr = new Point[len];
	}
	Point& operator[](int idx)
	{
		if(idx<0 || idx >= len)
		{
			cout << "Invalid index" << endl;
			exit(1);
		}
		return arr[idx];
	}
    int GetArrLen() const {
        return len;
    }
    
	~MyPointArray()
	{
		delete[] arr;
	}
};

int main(void)
{
    MyPointArray arr(3);
    arr[0] = Point(3, 4);
    arr[1] = Point(5, 6);
    arr[2] = Point(7, 8);
    
    for(int i=0; i<arr.GetArrLen(); i++)
        cout << arr[i] << endl;
    return 0;
}