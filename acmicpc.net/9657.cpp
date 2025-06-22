#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

// 19:25
int main()
{
	int n;

	cin >> n;
	dp.assign(n + 1, 0);

	dp[2] = 1;
	int arr[3] = { 1, 3, 4 };
	for (int i = 5; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int diff = i - arr[j];
			if (diff > 0)
			{
				dp[i] = 1;
				if (dp[diff] == 1)
				{
					dp[i] = 0;
					break;
				}
			}
		}
	}

	cout << (dp[n] == 0 ? "SK" : "CY") << "\n";
}