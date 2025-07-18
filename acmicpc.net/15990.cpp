//13:27
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	vector<vector<int>> dp(100001, vector<int>(4, 0));
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	int idx = 4;
	while (n--)
	{
		int x;
		cin >> x;
		for (; idx <= x; idx++)
		{
			dp[idx][1] = dp[idx - 1][2] + dp[idx - 1][3];
			dp[idx][2] = dp[idx - 2][1] + dp[idx - 2][3];
			dp[idx][3] = dp[idx - 3][1] + dp[idx - 3][2];

			for (int j = 1; j < 4; j++)
			{
				dp[idx][j] %= 1000000009;
			}
		}
		int sum = 0;
		for (int i = 1; i < 4; i++)
		{
			sum += dp[x][i];
			sum %= 1000000009;
		}

		cout << sum << "\n";
	}
}