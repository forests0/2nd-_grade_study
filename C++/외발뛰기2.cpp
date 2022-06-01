#include <iostream>
using namespace std;

int check[100][100];

int n;
int board[100][100];

void init()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            check[i][j] = -1;
        }
    }
}

bool jump(int x, int y)
{
    if (x == n - 1 && y == n - 1)
        return true;
    else if (x >= n || y >= n)
        return false;

    if (check[x][y] != -1)
        return check[x][y];

    for (int i = 0; i < n; i++)
    {
        check[i%n][i%n] = jump(x + board[i%n][i%n], y) || jump(x, y + board[i%n][i%n]);   
    }
    return check[n][n];
}

int main()
{
    cin >> n;

    init();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    if (jump(0, 0))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}