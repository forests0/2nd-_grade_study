#include <iostream>
using namespace std;

int n, m;
int heights[10000001];
int res = -1;

void Find(int start, int end) {
    if(start > end) return;
    int mid = (start + end) / 2;
    int cus = 0;
    for(int i = 0; i < n; i++) {
        cus += (heights[i] - mid) > 0 ? heights[i] - mid : 0; 
    }
    if(cus < m) {
        Find(start, mid -1);
    }
    else if(cus > m) {
        res = mid;
        Find(mid + 1, end);
    }
    else {
        res = mid;
        return;
    }
}

int main() {
    cin>>n>>m;
    int max = -1;
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
        if(max < heights[i]) max = heights[i];
    }
    Find(0, max);
    cout<<res<<endl;
}