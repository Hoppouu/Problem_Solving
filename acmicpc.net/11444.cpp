//14:50
#include <iostream>
#include <cmath>
#define MOD 1000000007
using namespace std;
using ll = long long;
ll result[2][2]
{
	{1, 0},
	{0, 1}
};

ll dp[65][2][2] =
{
	{
		{1, 1},
		{1, 0}
	}
};
void calc(int x)
{
	ll temp[2][2] =
	{
		{0, 0},
		{0, 0}
	};
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				temp[i][j] += result[i][k] * dp[x][k][j];

			}
			temp[i][j] %= MOD;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			result[i][j] = temp[i][j];

		}
	}
}

void set()
{
	for (int l = 1; l < 65; l++)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					dp[l][i][j] += dp[l - 1][i][k] * dp[l - 1][k][j];
					dp[l][i][j] %= MOD;
				}
			}
		}
	}
}
ll int_pow(ll base, int exp)
{
	ll result = 1;

	while (exp > 0)
	{
		if (exp % 2 == 1)
		{
			result *= base;
		}
		base *= base;
		exp /= 2;
	}
	return result;
}
void solve(long long n)
{
	set();
	long long t = n;

	while (t != 0)
	{
		int m = log(t) / log(2);
		t -= int_pow(2, m);
		calc(m);
	}
	
}
int main()
{
	long long n;
	cin >> n;
	solve(n);

	cout << result[0][1] << "\n";
}