#include <iostream>
#include <cstring>
using namespace std;

typedef struct Drink
{
    string name = "0";
    int money = 0;
    bool healthy = true;
} Dr;

typedef struct Drink1
{
    char name[20];
    int money = 0;
    bool healthy = true;
} Dr1;

int OUT(const string a)
{
    cout << a << "의 재고가 떨어져 구매가 불가합니다. 죄송합니다" << endl;
}
int OUT(int &m)
{
    cout << "어떤 음료인지 모르겠습니다." << endl;
}

int Remain(int remoney, int drinkmoney)
{
    int a = remoney - drinkmoney;
    if (a > 0)
    {
        return remoney - drinkmoney;
    }
    else
    {
    }
}

void Healthy(bool a)
{
    if (a)
    {
        cout << "감사합니다" << endl;
    }
    else
    {
        cout << "다음에는 좀 더 건강한 음료를 선택하는 것도 좋습니다, 감사합니다" << endl;
    }
}

void Result(Dr *a, int b, int c = 0)
{
    cout << "선택하신 음료는" << a->name << "이고, 금액은" << a->money << "입니다" << endl;
    if (b > 0)
    {
        cout << a->name << "을 구매하셨고, 남은 금액" << b << "반환했습니다" << endl;
    }
    else
    {
        cout << "금액이 부족하여 넣은 금액" << c << "원을 반환했습니다" << endl;
    }
    Healthy(a->healthy);
}

int MakeDrink()
{
    char newdrink[20];
    int newmoney;
    Dr1 *a4 = new Dr1;
    cin >> newdrink;
    strcpy(a4->name, newdrink);
    cin >> newmoney;
    a4->money = newmoney;
    cout << newmoney << "원의 새 음료 " << newdrink << "을 자판기에 넣었습니다." << endl;
}

int main()
{
    Dr *a1 = new Dr;
    a1->money = 1800;
    a1->name = "포카리스웨트";

    Dr *a2 = new Dr;
    a2->money = 1000;
    a2->name = "삼다수";

    Dr *a3 = new Dr;
    a3->money = 2000;
    a3->name = "콜라(펩시)";
    a3->healthy = false;
    int start;
    int num;
    int mon;
    int &test = mon;
    const string na1 = "사이다";

    while (true)
    {
        cout << "=========간이음료자판기=========="
             << "\n"
             << "1번 : 음료고르기 | 2번 : 음료 넣기 | 3번 : 끝내기" << endl;
        cin >> start;
        switch (start)
        {
        case 1:
        {
            //미리 만들어놓은 음료를 뽑는 코드들
            cout << "어떤 음료를 선택하시겠습니까?"
                 << "\n"
                 << "1 ~ 3번까지 있습니다." << endl;
            cin >> num;
            cout << "현재 얼마를 가지고 계신가요?" << endl;
        }
            switch (num)
            {
            case 1:
            {
                cin >> mon;
                Dr *re = new Dr;
                re->money = mon;

                Dr *remains = new Dr;
                remains->money = Remain(re->money, a1->money);
                Result(a1, remains->money, mon);
                break;
            }
            case 2:
            {
                cin >> mon;
                Dr *re = new Dr;
                re->money = mon;

                Dr *remains = new Dr;
                remains->money = Remain(re->money, a2->money);
                Result(a2, remains->money, mon);
                break;
            }
            case 3:
            {
                cin >> mon;
                Dr *re = new Dr;
                re->money = mon;

                Dr *remains = new Dr;
                remains->money = Remain(re->money, a3->money);
                Result(a3, remains->money, mon);
                break;
            }
            case 4:
                OUT(na1);
                break;
            default:
                OUT(test);
                break;
            }
            break;
        case 2:
        {
            //새로운 음료를 넣는 코드(넣기만 가능)
            MakeDrink();
            break;
        }
        case 3:
        {
            // 끝내는 코드
            delete a1;
            delete a2;
            delete a3;
            return 0;
        default:
            cout << "없는 수입니다" << endl;
        }
        }
    }
}
