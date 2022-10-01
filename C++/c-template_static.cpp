#include <iostream>
using namespace std;

class StaticTest {
private:
	static int num;
public:
	void Add(int num) { this->num += num; }
	void Show() { cout << num << endl;}
};

int StaticTest::num = 0;

int main(void) {
	StaticTest st1;
	st1.Add(5);
	st1.Show();

	StaticTest st2;
	st2.Add(5);
	st2.Show();
	return 0;
}