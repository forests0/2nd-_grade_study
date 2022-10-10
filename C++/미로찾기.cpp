#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n,m;
int board[201][201];
int visited[201][201];
queue<pair<int, int>> q;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool isvaild(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    return true;
}

void BFS(int x, int y) {
    visited[x][y] = 1;
    q.push(pair<int, int>(x,y));
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        int curx = cur.first;
        int cury = cur.second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nextx = curx + dx[i];
            int nexty = cury + dy[i];

            if(isvaild(nextx, nexty) && visited[nextx][nexty] == 0) {
                visited[nextx][nexty] = 1;
                q.push(pair<int,int>(nextx,nexty));
            }
        }
    }
}

int main() {
    cin>>n>>m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>board[i][j];
       }
    }
    BFS(0,0);
}