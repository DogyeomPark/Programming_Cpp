#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char * name;
	int age;
public:
	Person(const char* myname, int myage)
	{
		cout << "������ ȣ��" << endl;
		int len = strlen(myname) + 1;
		name = new char[len];
		cout << " new �����Ҵ� " << endl;
		strcpy_s(name, strlen(myname), myname);
		age = myage;
	}
	Person(const Person& copy) : age(copy.age)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy_s(name, strlen(copy.name), copy.name);
	}
	void ShowPersonInfo() const
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "�Ҹ��� ȣ��" << endl;
	}
};

int main()
{
	Person man1("Lee dong woo", 29);
	Person man2 = man1; //Person
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}