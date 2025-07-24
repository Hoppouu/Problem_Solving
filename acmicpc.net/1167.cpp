#include <iostream>
#include <vector>
using namespace std;

using pii = pair<int, int>;
vector<vector<pii>> tree;
vector<int> used, dist;
int n;

void dfs(int node, int cost, int level)
{
	used[node] = level;
	bool flag = true;
	for (int i = 0; i < tree[node].size(); i++)
	{
		int next_node = tree[node][i].first;
		int next_cost = tree[node][i].second;
		if (!used[next_node])
		{
			flag = false;
			dfs(next_node, cost + next_cost, level + 1);
		}
	}

	if (flag)
	{
		dist[node] = cost;
	}

}

int solve()
{
	used.assign(n + 1, 0);
	dist.assign(n + 1, 0);
	dfs(1, 0, 1);

	int level = 0;
	int node = 0;
	for (int i = 1; i < used.size(); i++)
	{
		if (level < used[i])
		{
			level = used[i];
			node = i;
		}
	}
	vector<int> nodes;
	for (int i = 1; i < used.size(); i++)
	{
		if (used[i] == level)
		{
			nodes.push_back(i);
		}
	}
	int cost = 0;
	for (int i = 0; i < nodes.size(); i++)
	{
		used.assign(n + 1, 0);
		dist.assign(n + 1, 0);
		dfs(nodes[i], 0, 1);

		for (int j = 1; j <= n; j++)
		{
			cost = max(cost, dist[j]);
		}
	}

	return cost;
}

int main()
{
	cin >> n;
	tree.assign(n + 1, vector<pii>());
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a;

		while (true)
		{
			cin >> b;
			if (b == -1)
			{
				break;
			}
			cin >> c;

			tree[a].push_back({ b, c });
		}
	}
	cout << solve() << "\n";
}