#include <stdio.h>
#include <iostream>
using namespace std;

int Add(int a, int b)
{
	return a + b;
}

float Add(float a, float b)
{
	return a + b;
}

int main()
{
	int num = 20;

	cout << "Hello World!!!" << endl;
	cout << "Hello " << "World!!!!" << endl;
	cout << num << ' ' << 'A' << endl << endl;

	int val1;
	cout << "ù ��° ���� �Է�: ";
	cin >> val1; // scanf_s("%d", &val1); �̷��� �ϴ°��� �����ϰ� ��

	int val2;
	cout << "�� ��° �����Է�: ";
	cin >> val2;

	int result = val1 + val2;
	cout << val1 << " + " << val2 << " = " << result << endl;

	return 0;
}