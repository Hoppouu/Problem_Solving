//17:41
#include <iostream>
using namespace std;
long long dp[36];
long long t(int n)
{
	if (dp[n])
	{
		return dp[n];
	}

	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += t(i) * t(n - 1 - i);
	}
	dp[n] = sum;
	return dp[n];
}

int main()
{
	dp[0] = 1;

	int n;
	cin >> n;

	cout << t(n);
}