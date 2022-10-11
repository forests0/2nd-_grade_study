#include <iostream>
#include <algorithm>
using namespace std;

int arr1[1000001];
int keys[1000001];

int BS(int first, int end, int key) {
    if(first <= end) return -1;
    int mid = (first + end) / 2;
    if(arr1[mid] < key) BS(first, mid - 1, key);
    else if(arr1[mid] > key) BS(mid + 1, end, key);
    else return 1;
}

bool Search(int start, int end, int key) {
    for(int i = 0; i < end; i++) {
        if(arr1[i] == key) return true;
    }
    return false;
}

int main() {
    int n, m;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>arr1[i];
    }
    cin>>m;
    for(int i = 0; i < m; i++) {
        cin>>keys[i];
    }
    sort(arr1, arr1 + n);
    for(int i = 0; i < m; i++) {
        if(BS(0, n, keys[i]) == 1) cout << "yes ";
        else cout << "no ";
    }

    for(int i = 0; i < m; i++) {
        if(Search(0, n, keys[i])) cout << "yes ";
        else cout << "no ";
    }
    return 0;
}
