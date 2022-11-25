#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, k, x;
int visited[300001];
vector<vector<int>> graph(300001);

int BFS() {
  queue<int> que;
  que.push(x);
  visited[x] = 1;
  while(!que.empty()) {
    int cur = que.front();
    que.pop();
    for(int i = 0; i < graph[cur].size(); i++) {
      int next = graph[cur][i];
      que.push(next);
      visited[next] = visited[cur] + 1;
    }
  }
}

int main() {
  cin>>n>>m>>k>>x;
  for(int i = 0; i < m; i++) {
    int start, end;
    cin>>start >> end;
    graph[start].push_back(end);
  }

  BFS();

  int count = 0;
  for(int i = 0; i <= n; i++) {
    if(visited[i] == k+1) {
      count++;
      cout << i << endl;
    }
  }
  if(count == 0) {
      cout<< -1 << endl;
    }
  return 0;
}