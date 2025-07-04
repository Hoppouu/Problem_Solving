#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF (1 << 30)
vector<vector<int>> map;
vector<vector<int>> dist;
queue<pair<int, int>> feed;
int n, nr, nc;
int dr[4] = { 0, -1, 1, 0 };
int dc[4] = { 1, 0, 0, -1 };
int minimum = INF;
int cur_size = 2;
bool check(int r, int c)
{
	return (0 <= r && r < n) && (0 <= c && c < n);
}

void bfs(int sr, int sc)
{
	queue<pair<int, int>> q;
	q.push({ sr, sc });
	dist[sr][sc] = INF;
	minimum = INF;
	int count = 0;
	while (!q.empty())
	{
		int size = q.size();
		count++;
		for (int k = 0; k < size; k++)
		{
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (check(nr, nc) && (dist[nr][nc] != INF && dist[nr][nc] == 0))
				{
					if (cur_size > map[nr][nc])
					{
						dist[nr][nc] = count;
						q.push({ nr, nc });
					}
					else if (cur_size == map[nr][nc])
					{
						dist[nr][nc] = INF;
						q.push({ nr, nc });
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (1 <= map[i][j] && map[i][j] <= 6 && cur_size > map[i][j])
			{
				if (dist[i][j] != 0)
				{
					minimum = min(minimum, dist[i][j]);
				}
			}
			else
			{
				dist[i][j] = 0;
			}
		}
	}
}
bool empty()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (1 <= map[i][j] && map[i][j] <= 6 && cur_size > map[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

int tr, tc;
void search()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dist[i][j] == minimum)
			{
				tr = i;
				tc = j;
				return;
			}
		}
	}
}
void solve()
{
	int time = 0;
	int cnt = 0;
	while (!empty())
	{
		dist.assign(n, vector<int>(n, 0));
		bfs(nr, nc);
		search();
		if (minimum == INF)
		{
			break;
		}
		time += minimum;
		cnt++;
		if (cnt == cur_size)
		{
			cnt = 0;
			cur_size++;
		}
		map[nr][nc] = 0;
		nr = tr, nc = tc;
		map[nr][nc] = 9;
	}

	cout << time << "\n";

}

int main()
{
	cin >> n;
	map.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				nr = i;
				nc = j;
			}
		}
	}

	solve();
}