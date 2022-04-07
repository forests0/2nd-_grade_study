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
    cout << a << "�� ��� ������ ���Ű� �Ұ��մϴ�. �˼��մϴ�" << endl;
}
int OUT(int &m)
{
    cout << "� �������� �𸣰ڽ��ϴ�." << endl;
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
        cout << "�����մϴ�" << endl;
    }
    else
    {
        cout << "�������� �� �� �ǰ��� ���Ḧ �����ϴ� �͵� �����ϴ�, �����մϴ�" << endl;
    }
}

void Result(Dr *a, int b, int c = 0)
{
    cout << "�����Ͻ� �����" << a->name << "�̰�, �ݾ���" << a->money << "�Դϴ�" << endl;
    if (b > 0)
    {
        cout << a->name << "�� �����ϼ̰�, ���� �ݾ�" << b << "��ȯ�߽��ϴ�" << endl;
    }
    else
    {
        cout << "�ݾ��� �����Ͽ� ���� �ݾ�" << c << "���� ��ȯ�߽��ϴ�" << endl;
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
    cout << newmoney << "���� �� ���� " << newdrink << "�� ���Ǳ⿡ �־����ϴ�." << endl;
}

int main()
{
    Dr *a1 = new Dr;
    a1->money = 1800;
    a1->name = "��ī������Ʈ";

    Dr *a2 = new Dr;
    a2->money = 1000;
    a2->name = "��ټ�";

    Dr *a3 = new Dr;
    a3->money = 2000;
    a3->name = "�ݶ�(���)";
    a3->healthy = false;
    int start;
    int num;
    int mon;
    int &test = mon;
    const string na1 = "���̴�";

    while (true)
    {
        cout << "=========�����������Ǳ�=========="
             << "\n"
             << "1�� : ������� | 2�� : ���� �ֱ� | 3�� : ������" << endl;
        cin >> start;
        switch (start)
        {
        case 1:
        {
            //�̸� �������� ���Ḧ �̴� �ڵ��
            cout << "� ���Ḧ �����Ͻðڽ��ϱ�?"
                 << "\n"
                 << "1 ~ 3������ �ֽ��ϴ�." << endl;
            cin >> num;
            cout << "���� �󸶸� ������ ��Ű���?" << endl;
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
            //���ο� ���Ḧ �ִ� �ڵ�(�ֱ⸸ ����)
            MakeDrink();
            break;
        }
        case 3:
        {
            // ������ �ڵ�
            delete a1;
            delete a2;
            delete a3;
            return 0;
        default:
            cout << "���� ���Դϴ�" << endl;
        }
        }
    }
}

