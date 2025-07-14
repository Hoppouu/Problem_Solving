//18:14
#include <iostream>
using namespace std;

int dp[1001][10];
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 0; i <= n; i++)
	{
		dp[i][9] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 8; j >= 0; j--)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j + 1];
			dp[i][j] %= 10007;

		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += dp[n][i];
	}
	sum %= 10007;
	cout << sum << "\n";
}