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
		//accID = ID; �̰� �̴ϼȶ������� ���ؼ� ^�� ó�� ��������.
	}

	int GetAccID() 
	{ 
		return accID;
	}

	void Deposit(int money)
	{
		balance += money;
	}

	int Withdraw(int money) //��ݾ� ��ȯ, ���� �� 0 ��ȯ
	{
		if (balance < money)
			return 0;

		balance -= money;
		return money;
	}

	void ShowAllAccInfo()
	{
		cout << "����ID: " << accID << endl;
		cout << "�� ��: " << cusName << endl;
		cout << "�� ��: " << balance << endl << endl;
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

Account * accArr[100]; //Account ������ ���� �迭
int accNum = 0;		// ����� Account ��

int main()
{
	int choice;

	while (1)
	{
		ShowMenu();
		cout << "����: ";
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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID :"; cin >> id;
	cout << "�� �� :"; cin >> name;
	cout << "�Աݾ� :"; cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney()
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "���� ID" << endl;
	cin >> id;
	cout << "�Աݾ�" << endl;
	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << money << "�� �ԱݿϷ� �Ǿ����ϴ�" << endl << endl;
			return;
		}
	}
	cout << id << "�� ��ȿ���� ���� ID �Դϴ�" << endl << endl;
}

void WithdrawMoney()
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money)==0)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}

			cout << money << "�� ��ݿϷ� �Ǿ����ϴ�" << endl << endl;
			return;
		}
	}
	cout << id << "�� ��ȿ���� ���� ID �Դϴ�" << endl << endl;
}

void ShowAllAccInfo()
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAllAccInfo();
		cout << endl;
	}
}
