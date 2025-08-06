//09:41
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int year = 2024;
	int m = 8;
	m += (n - 1) * 7;
	if (m % 12 == 0)
	{
		year += m / 12 - 1;
		m = 12;
	}
	else
	{
		year += m / 12;
		m %= 12;
	}
	cout << year << " " << m << "\n";
}