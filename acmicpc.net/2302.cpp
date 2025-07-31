//17:54
#include <iostream>
#include <vector>
using namespace std;

int dp[41];

int main()
{
	vector<int> fix;
	int n, m;
	cin >> n >> m;

	fix.push_back(0);
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		fix.push_back(x);
	}
	fix.push_back(n + 1);

	dp[0] = 1;
	dp[1] = 1;
	
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	
	int res = 1;
	for (int i = 1; i < fix.size(); i++)
	{
		res *= dp[fix[i] - fix[i - 1] - 1];
	}

	cout << res << "\n";
}