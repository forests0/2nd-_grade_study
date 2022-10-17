#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define INF 999999999

int n=6;
int start = 1;
vector<vector<pair<int,int>>> graph(n+1);
vector<bool> visited(n+1, false);
vector<int> dist(n+1, INF);

void init_graph() {
	graph[1].push_back(pair<int,int>(2, 2));
	graph[1].push_back(pair<int,int>(3, 5));
	graph[1].push_back(pair<int,int>(4, 1));
	graph[2].push_back(pair<int,int>(3, 3));
	graph[2].push_back(pair<int,int>(4, 2));
	graph[3].push_back(pair<int,int>(2, 3));
	graph[3].push_back(pair<int,int>(6, 5));
	graph[4].push_back(pair<int,int>(3, 3));
	graph[4].push_back(pair<int,int>(5, 1));
	graph[5].push_back(pair<int,int>(3, 1));
	graph[5].push_back(pair<int,int>(6, 2));
}

int findNode() {
    int snode;
    int scost = INF;
    for(int i = 0; i <=n; i++) {
        int ccost = dist[i];
        if(!visited[i] && scost > ccost) {
            snode = i;
            scost = ccost;
        }
    }
}

void Dijkstra() {
    dist[start] = 0;
    visited[start] = true;
    for(int i = 1; i < graph[start].size(); i++) {
        int next_node = graph[start][i].first;
        int edgecost = graph[start][i].second;
        int new_cost = dist[start] + edgecost;
        dist[next_node] = new_cost;
    }
    for(int i = 0; i <= n - 1; i++) {
        int curnode = findNode();
        visited[curnode] = true;
        for(int j = 0; j < graph[curnode].size(); j++) {
            int next_node = graph[curnode][i].first;
            int edgecost = graph[curnode][i].second;
            int new_cost = dist[curnode] + edgecost;
            if (dist[next_node] > new_cost) {
                dist[next_node] = new_cost;
            }
        }
    }
}

int main() {
	init_graph();
	Dijkstra();
	for(int i = 1 ; i <= n ; i++) {
		cout << dist[i] << endl;
	}
	return 0;
}