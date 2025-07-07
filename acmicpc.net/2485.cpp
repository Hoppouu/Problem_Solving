//09:40
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

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
int solve()
{
	int n, g = 1;
	for (int i = 1; i < v.size(); i++)
	{
		n = v[i] - v[i - 1];
		if (i == 1)
		{
			g = gcd(n, 0);
			continue;
		}
		g = gcd(n, g);
	}

	int cnt = 0;
	for (int i = 1; i < v.size(); i++)
	{
		n = v[i] - v[i - 1];
		cnt += n / g == 0 ? 0 : n / g - 1;
	}
	return cnt;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		v.push_back(n);
	}
	cout << solve() << "\n";
}