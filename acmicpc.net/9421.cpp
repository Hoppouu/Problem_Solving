#include <iostream>
#include <vector>
using namespace std;
int n;
int isPrime[1000001];
int memo[600]; // -1이면 1이 될 수 없음

bool solve1(int x)
{
	vector<int> v;

	int t = x;
	bool f;

	int sum = 0;
	while (sum != 1)
	{
		sum = 0;
		f = false;
		while (t != 0)
		{
			int a = t % 10;
			sum += a * a;
			t /= 10;
		}
		if (memo[sum] == -1)
		{
			f = true;
			break;
		}
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == sum)
			{
				f = true;
				break;
			}
		}
		v.push_back(sum);
		if (f)
		{
			break;
		}
		t = sum;
	}

	if (f)
	{
		if (memo[x] != -1)
		{
			v.push_back(x);
			for (int i = 0; i < v.size(); i++)
			{
				memo[v[i]] = -1;
			}
		}
	}

	return !f;
}

void solve()
{
	fill(isPrime, isPrime + n + 1, 1);
	for (int i = 2; i <= n; i++)
	{
		for (int j = i + i; j <= n; j += i)
		{
			isPrime[j] = 0;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (isPrime[i] && solve1(i) == 1)
		{
			cout << i << "\n";
		}
	}

}

int main()
{
	cin >> n;
	solve();
}