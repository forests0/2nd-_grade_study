#include <iostream>
using namespace std;
int n;
int board[101][101];
bool memo[101][101];
void init(int val) {
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            memo[i][j] = val;
        }
    }
}
int Jump(int x, int y)
{

    if (x == n - 1 && y == n - 1) return true;
    if (x >= n || y >= n) return false;
    if (memo[x][y] != -1) return memo[x][y]; 
    int jumpsize = board[x][y];
    memo[x][y] =  Jump(x + jumpsize, y) || Jump(x, y + jumpsize);
    return memo[x][y];
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }
    init(-1);
    bool result = Jump(0, 0);
    if (result)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}