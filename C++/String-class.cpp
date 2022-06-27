#include <iostream>
#include <string>
using namespace std;

class String {
    private:
    int len;
    char * str;
    public :
    String() {};
    String(const char* s){
        str = new char[ + 1];
        
    };
    String(const String* s) {};
    ~String() {
        delete[] str;
    }
};

int main(void)
{
	string str1 = "I like ";
	string str2 = "string class";
	string str3 = str1+str2;
	
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	
	str1 += str2;
	if(str1 == str3)
		cout << "동일 문자열!" << endl;
	else
		cout << "다른 문자열!" << endl;
	
	string str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;
	return 0;
}