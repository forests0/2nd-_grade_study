#include <iostream>
#include <queue>
using namespace std;

int arr[8][8] = {
	{ 0, 1, 1, 0, 0, 0, 0, 1},
	{ 1, 0, 0, 0, 0, 0, 1, 0},
	{ 1, 0, 0, 1, 1, 0, 0, 0},
	{ 0, 0, 1, 0, 1, 0, 0, 0},
	{ 0, 0, 1, 1, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 1, 0},
	{ 0, 1, 0, 0, 0, 1, 0, 1},
	{ 1, 0, 0, 0, 0, 0, 1, 0}
};
int visited[8];

queue<int> q;
int BFS(int x) {
    q.push(x);
    visited[x] = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ",";
        for(int i = 0; i < 8; i++) {
            if(arr[cur][i] == 1) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    BFS(0);
}
