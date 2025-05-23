#include <iostream>
using namespace std;
int n, m, x, y;
int gcd(int a, int b)
{
	int t;
	while (b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	}

	return a;
}

int lcm(int a, int b)
{
	int x = gcd(a, b);
	return x * a / x * b / x;
}

int solve()
{
	int x_gcd = gcd(n, m);
	if (abs(x - y) % x_gcd != 0)
	{
		return -1;
	}
	int k;
	for (k = 0; (n * k + x % n) % m != y % m; k++);
	int nlcm = lcm(n, m);
	return (n * k + x % n) % nlcm  == 0 ? nlcm : (n * k + x % n) % nlcm;

}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> m >> x >> y;
		cout << solve() << "\n";
	}
}