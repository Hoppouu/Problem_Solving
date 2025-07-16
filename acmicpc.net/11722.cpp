//09:53
#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
vector<int> dp;
int main()
{
	int n;
	cin >> n;

	while (n--)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	dp.assign(v.size(), 1);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i] < v[j])
			{
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}

	int m = 0;
	for (int i = 0; i < dp.size(); i++)
	{
		m = max(m, dp[i]);
	}

	cout << m << "\n";
}