#include <iostream>
using namespace std;

int cnt[51];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		cnt[x]++;
	}

	int t = 0;
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] != 0)
		{
			t++;
		}
	}
	int r = 0;
	for (int i = 1; i <= t; i++)
	{
		int t = 1;
		for (int j = 1; j <= i; j++)
		{
			if (cnt[i] != 0)
			{
				t *= cnt[j];
			}
			else
			{
				t = 0;
				break;
			}
		}
		r += t;
	}

	cout << r << "\n";
}