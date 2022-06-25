#include <iostream>
#include <vector>
using namespace std;

int lis1(vector<int> & target) {
    if(target.empty()) return 0;
    int ret = 0;
    for(int i = 0; i < target.size(); i++) {
        vector<int> target2;
        for(int j = i + 1; j < target.size();j++) {
            if(target[j] > target[i]) target.push_back(j);
            ret = max(ret, 1 + lis1(target2));
        }
    }
    return ret;
}

int n;
int target2[500];

int lis2(int start) {
    if(start == n) return 0;
    int ret = 1;
    for(int i = start + 1; i < n; i++) {
        if(target2[start] < target2[i]) ret = max(ret, lis2(i));
    }
    return ret;
}

int cache[100];
int init(int val) {
    for(int i = 0; i < 100; i++) {
        cache[i] = val;
    }
}

int lis3(int start) {
    if(cache[start] != -1) return cache[start];
    int ret = 1;
    for(int i = start + 1; i < n; i++) {
        if(target2[start] < target2[i]) ret = max(ret, lis3(i));
    }
    cache[start] = ret;
    return cache[start];
}

int main() {
	init(-1);

    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>target2[i];
    }
    int ret = 0;
    for(int i = 0; i < n; i++) {
        ret = max(ret, lis3(i));
    }
    cout<<ret<<endl;
}