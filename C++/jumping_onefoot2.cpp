#include <iostream>
using namespace std;

int n;
int board[100][100];
int possibility[100][100];

void init()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            possibility[i][j] = -1;
        }
    }
}
bool jump(int x, int y)
{
    for (int i = n - 1; i >= x; i--)
    {
        for (int j = n - 1; j >= x; j--)
        {
            if (i == n - 1 && j == n - 1)
                possibility[i][j] = 1;
            int jumpsize = board[i][j];
            if (i + jumpsize >= n && j + jumpsize >= n)
                possibility[i][j] = 0;
            else if (i + jumpsize >= n)
                possibility[i][j] = possibility[i][j + jumpsize];
            else if (j + jumpsize >= n)
                possibility[i][j] = possibility[i + jumpsize][j];
            else
            {
                possibility[i][j] = possibility[i + jumpsize][j] || possibility[i][j + jumpsize];
            }
        }
    }
    return possibility[x][y];
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