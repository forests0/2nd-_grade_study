#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num;
public:
	SimpleClass(int n)
	{
		num = n;
	}
	int GetNum() const
	{
		return num;
	}
};

class SimpleClass2 {
    private :
    int num1, num2;
    public :
    SimpleClass2(int n1, int n2) {
        num1 = n1;
        num2 = n2;
    }
    void showData() {
        cout<<num1<<","<<num2<<endl;
    }
};
int main(void)
{
	SimpleClass sc(2);
	cout << sc.GetNum() << endl;

    SimpleClass2 sr(10, 2);
    sr.showData();
	return 0;
}