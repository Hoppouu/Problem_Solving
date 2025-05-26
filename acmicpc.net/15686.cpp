#include <iostream>
#include <vector>
using namespace std;

int n, m, ans = 1 << 30;
vector<pair<int, int>> house, store, selected;
int c= 0;
int dist(int r1, int c1, int r2, int c2)
{
	return abs(r1 - r2) + abs(c1 - c2);
}

int solve1()
{
	int sum = 0;
	for (int i = 0; i < house.size(); i++)
	{
		int minx = 1 << 30;
		int r1 = house[i].first, c1 = house[i].second;
		for(int j = 0; j < selected.size(); j++)
		{
			int r2 = selected[j].first, c2 = selected[j].second;
			minx = min(dist(r1, c1, r2, c2), minx);
		}
		sum += minx;
	}
	return sum;
}

void solve(int k, int a)
{
	if (k == m)
	{
		ans = min(solve1(), ans);
		return;
	}
	for (int i = a; i < store.size(); i++)
	{
		int r = store[i].first, c = store[i].second;
		selected[k]= {r, c};
		solve(k + 1, i + 1);
	}
}

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;
			if (x == 1)
			{
				house.push_back({ i, j });
			}
			else if (x == 2)
			{
				store.push_back({ i, j });
			}
		}
	}
	selected.assign(m, pair<int, int>());
	solve(0, 0);
	cout << ans << "\n";
}