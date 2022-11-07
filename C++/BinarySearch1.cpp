#include <iostream>
using namespace std;

int arrays[11] = {1,3,5,7,9,11,13,15,17,19};

int BS(int first, int end, int key) {
    if(first <= end) {
        int mid = first + end / 2;
        if(mid > key) BS(mid + 1, end, key);
        else if(mid == key) return mid;
        else BS(first, mid - 1, key);
    }
    return -1;
}

int BS2(int key) {
    int start = 0;
    int end = 9;
    while(start <= end) {
        int mid = start + end / 2;
        if(key < arrays[mid]) end = mid - 1;
        else if (key > arrays[mid]) start = mid + 1;
        else return mid;
    }
    return -1;
}

int main() {
    int search;
    cin>>search;

    cout << BS(0,9,search) << endl;
    cout << BS2(9) << endl;
}