//14:04
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	vector<int> dp(v.size(), 1);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (v[j] < v[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int m = 0;
	for (int i = 1; i <= n; i++)
	{
		m = max(m, dp[i]);
	}
	cout << m << "\n";
}