#include <iostream>
#include <cstring>
using namespace std;

class FruitSeller {
    private :
    int Applepr;
    int numofApple;
    int myMoney;
    public :
    void Init(int price, int num, int money) {
        Applepr = price;
        numofApple = num;
        myMoney = money;
    }
    int TellApplePrice() {
        return Applepr;
    }
    void ShowResult() {
        cout<< "남은 사과 : " << numofApple << endl;
        cout<< "판매 수익 : " << myMoney << endl;
    }
    int SaleApple(int money) {
        int num = money / Applepr;
        numofApple -= num;
        myMoney += money;
        return num; 
    }
};

class FruitBuyer {
    private :
    int Mymoney;
    int numofApple;
    public :
    void Init(int money) {
        Mymoney = money;
        numofApple = 0;
    }
    int BuyApples(int numofbuy, FruitSeller seller) {
        int a = seller.TellApplePrice();
        int payMoney = a * numofbuy;
        int applenum = seller.SaleApple(payMoney);
        numofApple += numofbuy;
        Mymoney -= payMoney;
        
        cout<< "사과장수에게 사과 " << applenum <<"개를 구입하셨습니다"<<endl;
    }
    
    void showBuyResult() {
        cout<< "현재 잔액 :  " << Mymoney << endl;
        cout<< "사과 개수 : " << numofApple << endl;
    }
};

int main() {
    FruitBuyer me;
    FruitSeller seller;

    seller.Init(1000,20,0);
    me.Init(5000);

    me.BuyApples(2, seller);

    cout<<"과일 판매자의 현황"<<endl;
    seller.ShowResult();
    cout<<endl;

    cout<<"과일 구매자의 현황"<<endl;
    me.showBuyResult();
    cout<<endl;
}