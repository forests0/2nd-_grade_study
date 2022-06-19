#include <iostream>
using namespace std;

class XYZ
{
private:
	int num;
public:
	XYZ(int num=0): num(num)
	{
		cout << "First(int num=0)" << endl;
	}
	XYZ(const XYZ& obj): num(obj.num)
	{
		cout << "First(const XYZ& obj)" << endl;
	}
	void ShowData() const
	{
		cout << num << endl;
	}
    XYZ& operator=(const XYZ& obj) {
        this->num = obj.num;
        return *this;
    }
};

int main(void)
{
	XYZ obj1(10);
	XYZ obj2 = obj1;
	XYZ obj3;
	obj3 = obj1;
	obj1.ShowData();
	obj2.ShowData();
	obj3.ShowData();
	return 0;
}