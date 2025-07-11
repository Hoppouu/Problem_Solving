//10:53
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, l, r, x;

int arr[15];
int used[15];
int cnt, m;
void calc()
{
	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		sum += arr[i];
	}
	if (l <= sum && sum <= r)
	{
		if (arr[m - 1] - arr[0] >= x)
		{
			cnt++;
		}
	}
}

void sol(int idx, int k)
{
	if (k == m)
	{
		calc();
		return;
	}

	for (int i = idx; i < v.size(); i++)
	{
		if (!used[i])
		{
			arr[k] = v[i];
			used[i] = 1;
			sol(i + 1, k + 1);
			used[i] = 0;
		}
	}
}

void solve()
{
	int sum = 0;

	//1~n개 고르는 경우의 수
	for (int i = 1; i <= n; i++)
	{
		fill(used, used + 15, 0);
		m = i;
		sol(0, 0);
	}
}
int main()
{
	cin >> n >> l >> r >> x;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	solve();

	cout << cnt << "\n";
}