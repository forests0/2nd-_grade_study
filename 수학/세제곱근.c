#include <stdio.h>

double pow(double a, int n)
{
    if (a == 0) {
         return 0; 
    }

    int i = 0;
    double res = 1;

    for (i = 0; i < n; i++) {
        res *= a;
    }

    return res;
}

double root(double a, int n, double pre)
{
    double res = 1;

    while ((pow(res, n) - a) < - pre || (pow(res, n) - a) > pre)
    {
        res = res * (n - 1) / n + a / (n * pow(res, n - 1));
    }

    return res;
}

int main()
{
    int a, n;

    scanf("%d %d", &a, &n);

    printf("%f", root(a, n, 6));
}
