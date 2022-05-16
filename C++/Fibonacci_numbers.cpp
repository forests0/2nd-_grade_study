#include <iostream>
using namespace std;

int memo[100] = {1, 1};
int fibo(int n)
{
    if (n < 2)
        return n;
    if (memo[n] != 0)
    {
        return memo[n];
    }
    else
    {
        memo[n] = fibo(n - 1) + fibo(n - 2);
        return memo[n];
    }
}

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << i << "번째 항 : " << fibo(i) << endl;
    }
    return 0;
}