#include <iostream>
using namespace std;
int n, k;
int menu[100][2];
int sw[201];

//회전초밥의 선호도를 반복적 동적 계획법의 슬라이딩 윈도우를 사용해 해결
int Prefer() {
    k = k / 100;
    sw[0] = 0;
    for(int b = 1; b <= k; b++) {
        sw[b / 201] = 0; //예산이 20000원 이하이기 때문에 201로 나눠 간소화
        for(int s = 0; s < n; s++) {
            int tprice = menu[s][0] / 100;
            int tpref = menu[0][s];
            if(k < tprice) continue;
            sw[b % 201] = max(sw[b % 201], sw[(b - tprice) % 201] + tpref);
        }
    }
    return sw[k%201];
}

int main() {

    cin>>n>>k;
    for(int i = 0; i < n; i++) {
        cin>>menu[i][0]>>menu[i][1];
    }
    cout<<Prefer()<<endl;
}
