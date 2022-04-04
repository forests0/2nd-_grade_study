#include<iostream>
#include <tuple>
#include<queue>

using namespace std;
int n, a, b;
priority_queue<tuple<int,int,int>> pq;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i = 1; i <= n; i++) {
        cin >> a >> b;
        pq.push(make_tuple(a, b, -i));
    }
    for(int i = 0; i < n; i++) {
        tuple<int ,int, int> tmp = pq.top();
        cout<< -get<2>(tmp) << ' ' << get<0>(tmp) << ' ' << get<1>(tmp) << endl;
        pq.pop();
    }
    return 0;
}