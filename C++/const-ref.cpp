#include <iostream>
using namespace std;

int main() {
    const int num = 12; 
    const int *a = &num;
    const int *(&b) = a;

    cout<<*a<<' '<<*b;
}