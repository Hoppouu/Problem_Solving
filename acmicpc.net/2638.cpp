//14:12
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> map, cnt;
vector<vector<bool>> visited;

int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

bool check(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < m;
}

bool isEmpty()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1)
			{
				return false;
			}
		}
	}

	return true;
}

void solve1()
{
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		if (visited[r][c])
		{
			continue;
		}
		visited[r][c] = true;

		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (!check(nr, nc))
			{
				continue;
			}

			if (map[nr][nc] == 0)
			{
				q.push({ nr, nc });
			}
			else if (map[nr][nc] == 1)
			{
				cnt[nr][nc]++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (cnt[i][j] >= 2)
			{
				map[i][j] = 0;
			}
		}
	}
}

int solve()
{
	int time = 0;
	while (!isEmpty())
	{
		time++;
		cnt.assign(n, vector<int>(m, 0));
		visited.assign(n, vector<bool>(m, false));
		solve1();
	}
	return time;
}
int main()
{
	cin >> n >> m;
	map.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	cout << solve() << "\n";
}