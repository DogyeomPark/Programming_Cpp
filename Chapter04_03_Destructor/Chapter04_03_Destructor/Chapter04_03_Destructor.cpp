#include <iostream>
#include <cstring>
using namespace std;

class Person
{
public:
	Person(const char* myname, int myage)
	{
		cout << "###������ ȣ��###" << endl;
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, strlen(myname) +1, myname);
		age = myage;
	}
	void ShowPersonInfo()const
	{
		cout << "�̸�" << name << endl;
		cout << "����: " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "�Ҹ��� ȣ��::::" << endl;
	}

private:
	char* name;
	int age;
};

int main()
{
	Person man1("Lee dong woo", 29);
	Person man2("Jang dong gun", 41);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}