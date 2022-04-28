#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum
    {
        CLERK,
        SENIOR,
        ASSIST,
        MANAGER
    };
    void ShowpostInfo(int pos)
    {
        switch (pos)
        {
        case CLERK:
            cout << "사원" << endl;
            break;
        case SENIOR:
            cout << "주임" << endl;
            break;
        case ASSIST:
            cout << "대리" << endl;
            break;
        case MANAGER:
            cout << "과장" << endl;
        }
    }
}

class NameCard
{
public:
    char* name;
	char *comname;
	char* phone;
    int pos;
    NameCard(char* name, char* comname, char* phone, int pos) {
        name = new char[strlen(this->name) + 1];
        comname = new char[strlen(this->comname) + 1];
        phone = new char[strlen(this->phone) + 1];

        strcpy(this->name, name);
        strcpy(this->comname, comname);
        strcpy(this->phone, phone);
    }
    NameCard(const NameCard& n) : pos(n.pos) {
        name = new char[strlen(n.name) + 1];
        comname = new char[strlen(n.comname) + 1];
        phone = new char[strlen(n.phone) + 1];

        strcpy(n.name, name);
        strcpy(n.comname, comname);
        strcpy(n.phone, phone);
    }

    void showNameCardInfo() {
        cout<<"이름 : "<<name<<endl;
        cout<<"회사 이름 : "<<comname<<endl;
        cout<<"전화번호 : "<<phone<<endl;
        cout<<"직급 : ";
        COMP_POS::ShowpostInfo(pos);
    }
    ~NameCard() {
        delete[] name;
        delete[] comname;
        delete[] phone;
    }
};

int main() {
    NameCard n1("Lee", "Busan" , "010-1111-1122", COMP_POS::CLERK);
    NameCard copy1 = n1;
    NameCard n2("Hong", "Seoul" , "010-1234-1122", COMP_POS::SENIOR);
    NameCard copy2 = n2;

    copy1.showNameCardInfo();
    copy2.showNameCardInfo();
}