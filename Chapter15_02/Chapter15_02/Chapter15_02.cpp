#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	cout << "�� ���� ���� �Է�: ";
	cin >> num1 >> num2;

	/*if (num2 == 0)
	{
		cout << "0���δ� ���� �� �����ϴ�!!!!";
		return 1;
	}
	else
	{
		cout << "�������� ��: " << num1 / num2 << endl;
		cout << "�������� ������: " << num1 % num2 << endl;
	}*/

	try
	{
		if (num2 == 0)
			throw num2;
		cout << "�������� ��: " << num1 / num2 << endl;
		cout << "�������� ������: " << num1 % num2 << endl;
	}
	catch (int expn)
	{
		cout << num2 << "���� ���� �� �����ϴ�!!!" << endl;
	}

	cout << "End of Main" << endl << endl;
	return 0;
}