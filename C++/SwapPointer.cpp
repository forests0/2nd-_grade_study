#include <iostream>
using namespace std;
int SwapPointer(int *(&pt1), int *(&pt2)) {
    int *temp = pt1;
    pt1 = pt2;
    pt2 = temp;
}

int main() {
    int num1 = 5;
    int *ptr1 = &num1;
    int num2= 10;
    int *ptr2 = &num2;
    SwapPointer(ptr1, ptr2);
    cout<<*ptr1<<' '<<*ptr2<<endl;
    return 0; 
}