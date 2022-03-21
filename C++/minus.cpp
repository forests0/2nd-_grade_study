#include <iostream>
using namespace std;
int countup(int &val) {
    val += 1;
}
int minus1(int &val) {
    val = -val;
}
int main() {
    int val = 10;
    int val2 = 5;
    countup(val);
    minus1(val2);
    cout<<val<<' '<<val2<<endl;
}