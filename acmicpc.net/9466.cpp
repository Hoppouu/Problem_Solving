#include <iostream>
#include <vector>
using namespace std;

vector<int> v, used, memo;
int T, n, cnt;
void solve()
{
	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int cur, next;
		bool f = true;
		cur = i;
		next = v[i];
		while (true)
		{
			if (memo[cur] == 0 || memo[cur] == 1)
			{
				f = false;
				break;
			}
			else if (memo[cur] == -1 && !used[cur])
			{
				used[cur] = 1;
				cur = next;
				next = v[cur];
			}
			else
			{
				break;
			}
		}
		if (f)
		{
			while (memo[cur] == -1)
			{
				memo[cur] = 1;
				cur = next;
				next = v[cur];
			}
		}
		cur = i;
		next = v[cur];
		while (memo[cur] == -1)
		{
			memo[cur] = 0;
			cur = next;
			next = v[cur];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (memo[i] == 0)
		{
			cnt++;
		}
	}
}
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		v.assign(n + 1, 0);
		used.assign(n + 1, 0);
		memo.assign(n + 1, -1); //-1->미정, 0->팀 없음, 1->팀 있음
		for (int i = 1; i <= n; i++)
		{
			cin >> v[i];
		}
		solve();
		cout << cnt << "\n";
	}
}