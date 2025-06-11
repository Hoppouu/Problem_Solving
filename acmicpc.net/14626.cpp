#include <iostream>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int sum = 0, t = 1;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != '*')
		{
			sum += (str[i] - '0') * (i % 2 == 0 ? 1 : 3);
		}
		else
		{
			t = i % 2 == 0 ? 1 : 3;
		}
	}
	int r = 10 - sum % 10;
	r = r * (t == 3 ? 7 : 1);
	r %= 10;
	cout << r << "\n";

}