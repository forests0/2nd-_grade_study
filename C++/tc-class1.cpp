#include <iostream>
#include <cstring>
using namespace std;

class AccountException {
public:
	virtual void ShowExceptionReason() = 0;
};

class DepositException: public AccountException {
private:
	int reqDep;
public:
	DepositException(int money): reqDep(money) {}
	virtual void ShowExceptionReason() {
		cout << "입금 실패: " << reqDep <<" 입금불가" << endl;
	}
};

class WithdrawException: public AccountException {
private:
	int balance;
public:
	WithdrawException(int money): balance(money) {}
	virtual void ShowExceptionReason() {
		cout << "출금 실패: " << "잔액 " << balance <<", 잔액 부족" << endl;
	}
};

class Account {
private:
	char accNum[100];
	int balance;
public:
	Account(char* acc, int money): balance(money) {
		strcpy(accNum, acc);
	}
	void Deposit(int money) throw(AccountException) {
		if(money < 0) {
			throw DepositException(money);
		}
		balance += money;
	}
	void Withdraw(int money) throw(AccountException) {
		if(money > balance) {
			throw WithdrawException(balance);
		}
		balance -= money;
	}
	void ShowMyMoney() {
		cout << "잔고: " << balance << endl << endl;
	}
};

int main(void) {
	char accNum[100] = "1234";
	Account acc(accNum, 1000);
	
	try {
		acc.Deposit(1000);
		acc.Deposit(-100);
	}
	catch(AccountException& expn) {
		expn.ShowExceptionReason();
	}
	acc.ShowMyMoney();
	
	try {
		acc.Withdraw(2000);
		acc.Withdraw(1000);
	}
	catch(AccountException& expn) {
		expn.ShowExceptionReason();
	}
	acc.ShowMyMoney();
	
	return 0;
}