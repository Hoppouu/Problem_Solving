//09:54
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> v;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	vector<int> dp;
	dp.assign(v.size(), 0);
	dp[0] = v[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = v[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (v[j] < v[i])
			{
				dp[i] = max(dp[i], dp[j] + v[i]);
			}
		}
	}

	int m = 0;
	for (int i = 0; i < n; i++)
	{
		m = max(m, dp[i]);
	}

	cout << m << "\n";
}