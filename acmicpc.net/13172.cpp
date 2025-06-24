//16:49
#include <iostream>
#define M 1000000007
using namespace std;
int t;
typedef long long ll;

ll x, y;
ll extended_gcd(ll a, ll b)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int gcd = extended_gcd(b, a % b);
	ll x1 = x;
	ll y1 = y;
	x = y1;
	y = x1 - (a / b) * y1;
	return gcd;
}

int gcd(int a, int b)
{
	while (b != 0)
	{
		int t = a;
		a = b;
		b = t % b;
	}

	return a;
}

int solve(int a, int b)
{
	int g = gcd(a, b);
	a /= g;
	b /= g;
	extended_gcd(a, M);
	ll inv = (x % M + M) % M;
	return b * inv % M;
}

int main()
{
	cin >> t;
	int a, b;
	ll sum = 0;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;

		sum = (sum + solve(a, b)) % M;
	}
	cout << sum << "\n";
}