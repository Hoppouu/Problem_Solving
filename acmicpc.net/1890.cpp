//09:42
#include <iostream>
using namespace std;
using ll = long long;

ll arr[100][100];
ll dp[100][100];
int n;

bool check(int r, int c)
{
	return 0 <= r && r < n && 0 <= c && c < n;
}

int main()
{
	dp[0][0] = 1;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == n - 1 && j == n - 1)
			{
				continue;
			}
			ll t = arr[i][j];
			if (check(i + t, j))
			{
				dp[i + t][j] += dp[i][j];
			}

			if (check(i, j + t))
			{
				dp[i][j + t] += dp[i][j];
			}
		}
	}
	cout << dp[~-n][~-n];


}