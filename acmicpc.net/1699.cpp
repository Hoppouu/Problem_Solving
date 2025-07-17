//10:03
#include <iostream>
#include <vector>
#define INF ((1 << 31) - 1)
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> dp(n + 1, INF);
	for (int i = 1; i * i <= n; i++)
	{
		dp[i * i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j * j < i; j++)
		{
			dp[i] = min(dp[i - j * j] + dp[j * j], dp[i]);
		}
	}

	cout << dp[n] << "\n";
}