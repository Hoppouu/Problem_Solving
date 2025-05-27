#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> dp;
int main()
{
	cin >> n;

	dp.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		dp.push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + dp[j]);
		}
	}

	cout << dp[n] << "\n";
}