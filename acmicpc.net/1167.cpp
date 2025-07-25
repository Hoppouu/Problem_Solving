//10:50
#include <iostream>
#include <vector>
using namespace std;

using pii = pair<int, int>;
vector<vector<pii>> tree;
vector<int> used, dist;
int n;

void dfs(int node, int cost)
{
	used[node] = 1;
	dist[node] = cost;
	for (int i = 0; i < tree[node].size(); i++)
	{
		int next_node = tree[node][i].first;
		int next_cost = tree[node][i].second;
		if (!used[next_node])
		{
			dfs(next_node, cost + next_cost);
		}
	}

}

int solve()
{
	used.assign(n + 1, 0);
	dist.assign(n + 1, 0);
	dfs(1, 0);

	int cost = 0;
	int node = 0;
	for (int i = 1; i <= n; i++)
	{
		if (cost < dist[i])
		{
			cost = dist[i];
			node = i;
		}
	}

	used.assign(n + 1, 0);
	dist.assign(n + 1, 0);
	dfs(node, 0);


	cost = 0;
	for (int i = 1; i <= n; i++)
	{
		cost = max(cost, dist[i]);
	}

	return cost;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
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