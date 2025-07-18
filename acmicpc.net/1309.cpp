//10:17
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	vector<vector<int>> dp;
	int n;
	cin >> n;
	dp.assign(n + 1, vector<int>(3, 0));
	for (int i = 0; i < 3; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][1] + dp[i - 1][2];
		dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
		dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];

		for (int j = 0; j < 3; j++)
		{
			dp[i][j] %= 9901;
		}
	}

	int sum = 0;

	for (int i = 0; i < 3; i++)
	{
		sum += dp[n][i];
		sum %= 9901;
	}

	cout << sum << "\n";
}