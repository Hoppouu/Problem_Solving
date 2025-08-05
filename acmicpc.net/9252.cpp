//14:55
#include <iostream>
using namespace std;
int dp[1001][1001];
string str1, str2;

void solve(int i, int j)
{
	if (dp[i][j] == 0)
	{
		return;
	}
	while (dp[i][j - 1] == dp[i][j])
	{
		j--;
	}
	while (dp[i - 1][j] == dp[i][j])
	{
		i--;
	}

	solve(i - 1, j - 1);
	cout << str1[i - 1];
}

int main()
{
	cin >> str1 >> str2;

	for (int i = 0; i < str1.length(); i++)
	{
		for (int j = 0; j < str2.length(); j++)
		{
			dp[1 + i][1 + j] = max(dp[i][1 + j], dp[1 + i][j]);
			if (str1[i] == str2[j])
			{
				dp[1 + i][1 + j] = dp[i][j] + 1;
			}
		}
	}
	cout << dp[str1.length()][str2.length()] << "\n";
	solve(str1.length(), str2.length());
}