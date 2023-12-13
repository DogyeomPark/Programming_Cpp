#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	cout << "µÎ °³ÀÇ ¼ıÀÚ ÀÔ·Â: ";
	cin >> num1 >> num2;

	/*if (num2 == 0)
	{
		cout << "0À¸·Î´Â ³ª´­ ¼ö ¾ø½À´Ï´Ù!!!!";
		return 1;
	}
	else
	{
		cout << "³ª´°¼ÀÀÇ ¸ò: " << num1 / num2 << endl;
		cout << "³ª´°¼ÀÀÇ ³ª¸ÓÁö: " << num1 % num2 << endl;
	}*/

	try
	{
		if (num2 == 0)
			throw num2;
		cout << "³ª´°¼ÀÀÇ ¸ò: " << num1 / num2 << endl;
		cout << "³ª´°¼ÀÀÇ ³ª¸ÓÁö: " << num1 % num2 << endl;
	}
	catch (int expn)
	{
		cout << num2 << "À¸·Î ³ª´­ ¼ö ¾ø½À´Ï´Ù!!!" << endl;
	}

	cout << "End of Main" << endl << endl;
	return 0;
}