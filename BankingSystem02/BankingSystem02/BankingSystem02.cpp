#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void ShowAllAccInfo();

enum
{
	MAKE = 1,
	DEPOSIT,
	WITHDRAW,
	INQUIRE,
	EXIT
};

class Account
{
public:
	Account(int ID, int money, const char* name): accID(ID), balance(money)
	{
		cusName = new char[strlen(name) + 1];
		strcpy_s(cusName, strlen(name) + 1, name);
		//accID = ID; 이걸 이니셜라이져를 통해서 ^ㄴ 처럼 쓸수있음.
	}

	int GetAccID() 
	{ 
		return accID;
	}

	void Deposit(int money)
	{
		balance += money;
	}

	int Withdraw(int money) //출금액 반환, 부족 시 0 반환
	{
		if (balance < money)
			return 0;

		balance -= money;
		return money;
	}

	void ShowAllAccInfo()
	{
		cout << "계좌ID: " << accID << endl;
		cout << "이 름: " << cusName << endl;
		cout << "잔 액: " << balance << endl << endl;
	}
	~Account()
	{
		delete[]cusName;
	};

private:
	int accID;
	int balance;
	char* cusName;
};

Account * accArr[100]; //Account 저장을 위한 배열
int accNum = 0;		// 저장된 Account 수

int main()
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			for (int i = 0; i < accNum; i++)
				delete accArr[i];
			return 0;
		default:
			cout << "Illegal selection " << endl;
		}
	}
	return 0;
}

void ShowMenu()
{
	cout << "===== MENU =====" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID :"; cin >> id;
	cout << "이 름 :"; cin >> name;
	cout << "입금액 :"; cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney()
{
	int money;
	int id;
	cout << "[입 금]" << endl;
	cout << "계좌 ID" << endl;
	cin >> id;
	cout << "입금액" << endl;
	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << money << "가 입금완료 되었습니다" << endl << endl;
			return;
		}
	}
	cout << id << "는 유효하지 않은 ID 입니다" << endl << endl;
}

void WithdrawMoney()
{
	int money;
	int id;
	cout << "[출 금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money)==0)
			{
				cout << "잔액부족" << endl << endl;
				return;
			}

			cout << money << "가 출금완료 되었습니다" << endl << endl;
			return;
		}
	}
	cout << id << "는 유효하지 않은 ID 입니다" << endl << endl;
}

void ShowAllAccInfo()
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAllAccInfo();
		cout << endl;
	}
}
