#include <iostream>
#include <queue>
using namespace std;
int n,m;
int board[1001][1001];
queue<int> q_x;
queue<int> q_y;
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

bool isvalid(int x, int y) {
   if(x < 0 || x >= n || y < 0 || y >= m) return true;
  return true;
}

bool BFS(int x, int y) {
  if(!isvalid(x,y)) return false;
  if(board[x][y] == 1) return false;
	board[x][y] = 1;
  q_x.push(x);
  q_y.push(y);

  while(!q_x.empty() && !q_y.empty()) {
    int curx = q_x.front();
    int cury = q_y.front();

    q_x.pop();
    q_y.pop();

    for(int i = 0; i < 4; i++) {
      int nextx = curx + dx[i];
      int nexty = cury + dy[i];
      if(isvalid(nextx, nexty) && board[nextx][nexty] == 0) {
        board[nextx][nexty] = 1;
        q_x.push(nextx);
        q_y.push(nexty);
      }
    }
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