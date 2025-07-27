//17:47
#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[1001], dp[1001];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		dp[1] = arr[1];
		int m = dp[1];
		for (int i = 2; i <= n; i++)
		{
			dp[i] = max(arr[i] + dp[i - 1], arr[i]);
			m = max(dp[i], m);
		}
		cout << m << "\n";
	}
}