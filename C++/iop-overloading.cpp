#include <iostream>
using namespace std;

class MyIntArray {
    private :
    int *arr;
    int size;
    
    public :
    MyIntArray(int size): size(size) {
        arr = new int[size];
    }
    ~MyIntArray() {
        delete[] arr;

    }
    int& operator[] (int& i) {
        if(i >= size || i < 0) {
            cout<<"invalid index" << endl;
            exit(1);
        }
        return arr[i];
    }
};

int main() {
    MyIntArray arr(5);
    for(int i = 0; i < 5; i++) {
        arr[i] = i;
    }
    for(int i = 0; i < 5; i++) {
        cout<<arr[i];
    }
    return 0;
}