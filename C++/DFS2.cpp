#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr = {{1, 2, 7}, {0, 6}, {0, 3}, {2, 4}, {2, 3}, {6}, {1, 5}, {0, 6}};
int visited[8];

int DFS(int node)
{
    visited[node] = 1;
    cout << node << " ";
    for(int i = 0; i < arr[node].size(); i++) {
        if(visited[arr[node][i]] == 0) {
            DFS(arr[node][i]);
        }
    }
}

int main()
{
    DFS(0);
}