#include <iostream>
using namespace std;
int n,m;
int board[1001][1001];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool DFS(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    if(board[x][y] == 1) return false;
    board[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        DFS(x+dx[i], y+dy[i]);
    }
    return true;
}

int main() {
    int result = 0;
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>board[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(DFS(i, j) == true) result += 1;
        }
    }
    cout << result << endl;
}