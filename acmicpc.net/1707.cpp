//18:23
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> mark;
int k, v, e;


bool bfs(int start)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	queue<int> q;
	q.push(start);
	int m = 1;
	mark[start] = m;

	while (!q.empty())
	{
		int size = q.size();
		m *= -1;
		for (int i = 0; i < size; i++)
		{
			int cur = q.front(); q.pop();
			for (int j = 0; j < graph[cur].size(); j++)
			{
				int next = graph[cur][j];
				if (mark[next] == 0)
				{
					mark[next] = m;
					q.push(next);
				}
				else if (mark[next] == mark[cur])
				{
					return true;
				}
			}
		}

	}
	return false;
}

void solve()
{
	for (int i = 1; i <= v; i++)
	{
		if (mark[i] != 0)
		{
			continue;
		}
		if (bfs(i))
		{
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;

	while (k--)
	{
		cin >> v >> e;
		graph.assign(v + 1, vector<int>());
		mark.assign(v + 1, 0);
		for (int i = 0; i < e; i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		solve();
	}
}