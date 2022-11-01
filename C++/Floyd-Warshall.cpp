#include <iostream>
using namespace std;
#define INF 9999999

int n,m;
int graph[501][501];

void init_graph() {
  for (int i=1; i<=n; i++){
	for (int j=1; j<=n; j++){
	  graph[i][j] = INF;
	  if (i==j){
  		graph[i][j] = 0;
      }
	}
  }
}

int main() {
  cin>>n>>m;
  init_graph();
  for(int i = 1; i <= m; i++) {
    int start, end, cost;
    cin>>start>>end>>cost;
    graph[start][end] = cost;
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      for(int k = 1; k <= n; k++) {
        graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(graph[i][j] == INF) {
        cout<< -1 << ' ';
      }
      cout << graph[i][j] << ' ';
    }
    cout << endl;
  }
}