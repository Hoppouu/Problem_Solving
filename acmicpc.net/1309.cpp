//10:21
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	vector<vector<int>> dp;
	int n;
	cin >> n;
	dp.assign(2, vector<int>(3, 0));
	for (int i = 0; i < 3; i++)
	{
		dp[0][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		dp[1][0] = dp[0][1] + dp[0][2];
		dp[1][1] = dp[0][0] + dp[0][2];
		dp[1][2] = dp[0][0] + dp[0][1] + dp[0][2];

		for (int j = 0; j < 3; j++)
		{
			dp[0][j] = dp[1][j] % 9901;
		}
	}

	int sum = 0;

	for (int i = 0; i < 3; i++)
	{
		sum += dp[0][i];
		sum %= 9901;
	}

	cout << sum << "\n";
}