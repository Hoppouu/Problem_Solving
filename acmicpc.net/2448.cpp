#include <iostream>
#include <vector>
using namespace std;

void solve(int n, int r, int c)
{
	bool q = r % 3 == 0 && c % 6 == 2;
	bool w = r % 3 == 1 && (c % 6 == 1 || c % 6 == 3);
	bool e = r % 3 == 2 && c % 6 != 5;
	bool qq = r % 3 == 0 && c % 6 != 2;
	bool ww = r % 3 == 1 && (c % 6 != 1 && c % 6 != 3);
	bool ee = r % 3 == 2 && c % 6 == 5;
	if (n == 1)
	{
		cout << "*";
	}
	else if (qq || ww || ee)
	{
		cout << " ";
	}
	else
	{
		solve(n / 3, r / 3, c / 6);
	}
}
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n * 2; j++)
		{
			solve(n, i, j);
		}
		cout << "\n";
	}

}