//13:53
#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001][1001];

int main()
{
	int r, c;
	cin >> r >> c;

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> dp[i][j];
		}
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			dp[i][j] = dp[i][j] + max({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
		}
	}

	cout << dp[r][c] << "\n";
}