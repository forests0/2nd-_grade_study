#include <iostream>
using namespace std;
int memo[31][31];
int Bino(int n, int r) {
    if(r == 0 || r == n) return 1;
    if(memo[n][r] != 0) return memo[n][r];
    memo[n][r] = Bino(n-1, r-1) + Bino(n-1, r);
    return memo[n][r];
    
}

int main() {
    int n,r;
    cin>>n>>r;
    cout<<Bino(n,r);
}