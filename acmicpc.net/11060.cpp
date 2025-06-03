#include <iostream>
#include <vector>
#define INF (1 << 30)
using namespace std;

int main()
{
	vector<int> v, dp;
	int n;

	cin >> n;
	dp.assign(n + 1, INF);

	v.push_back(0);
	dp[1] = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (v[j] + j >= i)
			{
				dp[i] = min(dp[i], dp[j] + 1);
			}
		}
	}
	if (dp[n] == INF)
	{
		cout << "-1";
	}
	else
	{
		cout << dp[n];
	}
}