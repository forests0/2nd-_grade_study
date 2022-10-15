#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> arr = {{1, 2, 7}, {0, 6}, {0, 3}, {2, 4}, {2, 3}, {6}, {1, 5}, {0, 6}};
int visited[8];

queue<int> q;
int BFS(int x) {
    q.push(x);
    visited[x] = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ",";
        for(int i = 0; i < arr[cur].size(); i++) {
            int num = arr[cur][i];
            if(visited[num] == 0) {
                visited[num ] = 1;
                q.push(num);
            }
        }
    }
}


int main() {
    BFS(0);
}

