#include<iostream>
#include<vector>
using namespace std;
int numlist[100];
int Fibo_1(int n) {
    numlist[1] = 1;
    for(int i = 2; i <= n; i++) {
        numlist[i] = numlist[i-1] + numlist[i-2];
    }
    return numlist[n]; 
}

int Fibo_2(int n) {
    vector<int> numlist2;
    numlist2.push_back(0);
    numlist2.push_back(1);
    for(int i = 2; i <= n; i++) {
        numlist2.push_back(numlist2[i-1] + numlist2[i-2]);
    }
}

int Fibo_3(int n) {
    if(n <= 2) return 1;
    int n1 = 1;
    int n2 = 1;
    for(int i = 3; i <= n; i++) {
        int next = n1 + n2;
        n1 = n2;
        n2 = next;
    }
    return n2;
}

int Fibo_4(int n) {
    int numlist3[3];
    numlist[0] = 0;
    numlist[0] = 1;
    for(int i = 2; i <= n; i++) {
        numlist[i%3] = numlist[(i-1)%3] + numlist[(i-2)%3];
    }
    return numlist[n%3];
} // 슬라이딩윈도우


int main() {
    for(int i = 1; i <= 10; i++) {
        cout<<i<<"번째 항 : " << Fibo_1(i)<< endl;
    }
    for(int i = 1; i <= 10; i++) {
        cout<<i<<"번째 항 : " << Fibo_2(i)<< endl;
    }
    for(int i = 1; i <= 10; i++) {
        cout<<i<<"번째 항 : " << Fibo_3(i)<< endl;
    }
    for(int i = 1; i <= 10; i++) {
        cout<<i<<"번째 항 : " << Fibo_4(i)<< endl;
    }
}