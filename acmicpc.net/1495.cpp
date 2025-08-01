//17:39
#include <iostream>
#include <vector>
using namespace std;
int arr[51];
bool dp[51][1001];
int n, s, m;
int main()
{
	cin >> n >> s >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	dp[0][s] = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (dp[i - 1][j])
			{
				if (j + arr[i] <= m)
				{
					dp[i][j + arr[i]] = true;
				}
				if (j - arr[i] >= 0)
				{
					dp[i][j - arr[i]] = true;
				}
				
			}
		}
	}
	int res = -1;
	for (int i = m; i >= 0; i--)
	{
		if (dp[n][i])
		{
			res = i;
			break;
		}
	}
	cout << res << "\n";
}