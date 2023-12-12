#include <iostream>
using namespace std;

class PermanentWorker
{
private:
	char name[100];
	int salary;

public:
	PermanentWorker(const char* name, int money)
		: salary(money)
	{
		strcpy_s(this->name, name);
	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		cout << "name: " << name << endl;
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class EmPloyeeHandler
{
private:
	PermanentWorker* empList[50];
	int empNum;

public:
	EmPloyeeHandler(): empNum(0)
	{ }
	void AddEmployee(PermanentWorker* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const
	{
		int sum=0;
		for (int i = 0; i < empNum; i++)
			sum +=empList[i]->GetPay();
		cout << "salary sum: " << sum << endl;
	}
	~EmPloyeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}

	int main()
	{
		EmPloyeeHandler handler;

		handler.AddEmployee(new PermanentWorker("KIM", 1000));
		handler.AddEmployee(new PermanentWorker("LEE", 1500));
		handler.AddEmployee(new PermanentWorker("JUN", 2000));

		handler.ShowAllSalaryInfo();

		handler.ShowTotalSalary();
		return 0;
	}
};