#include <iostream>
#include <vector>
using namespace std;

int n, m, ans = 1 << 30;
vector<pair<int, int>> house, store;
vector<int> selected;

int dist(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y2 - y1);
}

int solve1()
{
	int sum = 0;
	for (int i = 0; i < house.size(); i++)
	{
		int minx = 1 << 30;
		int x1 = house[i].first, y1 = house[i].second;
		for(int j = 0; j < store.size(); j++)
		{
			if (selected[j])
			{
				int x2 = store[j].first, y2 = store[j].second;
				minx = min(dist(x1, y1, x2, y2), minx);
			}
		}
		sum += minx;
	}

	return sum;
}

void solve(int k)
{
	if (k == m)
	{
		ans = min(solve1(), ans);
		return;
	}
	for (int i = 0; i < store.size(); i++)
	{
		if (!selected[i])
		{
			selected[i] = 1;
			solve(k + 1);
			selected[i] = 0;
		}
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
	selected.assign(store.size(), 0);
	solve(0);

	cout << ans << "\n";
}