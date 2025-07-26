//15:10
#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[1001], dp[1001];
int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[0] = 1 << 30;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = arr[i];
		for (int j = 1; j < i; j++)
		{
			dp[i] = min(dp[i - j] + dp[j], dp[i]);
		}
	}

	cout << dp[n] << "\n";
}