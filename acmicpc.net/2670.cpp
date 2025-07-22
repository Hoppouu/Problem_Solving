//11:23
#include <iostream>
using namespace std;
double arr[10001];
double dp[10001];
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	dp[0] = arr[0];
	double m = arr[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(arr[i], dp[i - 1] * arr[i]);
		m = max(m, dp[i]);
	}

	cout << fixed;
	cout.precision(3);
	cout << m << "\n";
}