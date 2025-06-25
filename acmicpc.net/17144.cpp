// 07:46
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
int R, C, T;
vector<vector<int>> map;
queue<pii> q;
queue<int> v;

int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

int r, c;
bool check(int r, int c)
{
	return r >= 0 && r < R && c >= 0 && c < C;
}

void diffuse()
{
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (check(nr, nc) && map[nr][nc] != -1)
			{
				map[nr][nc] += v.front() / 5;
				map[r][c] -= v.front() / 5;
			}
		}
		v.pop();
	}
}

void work()
{
	for (int i = r - 1; i >= 1; i--)
	{
		map[i][0] = map[i - 1][0];
	}
	for (int i = r + 2; i <= R - 2; i++)
	{
		map[i][0] = map[i + 1][0];
	}

	for (int i = 0; i <= C - 2; i++)
	{
		map[0][i] = map[0][i + 1];
		map[R - 1][i] = map[R - 1][i + 1];
	}

	for (int i = 0; i <= r - 1; i++)
	{
		map[i][C - 1] = map[i + 1][C - 1];
	}
	for (int i = R - 1; i >= r + 2; i--)
	{
		map[i][C - 1] = map[i - 1][C - 1];
	}

	for (int i = C - 1; i >= c + 2; i--)
	{
		map[r][i] = map[r][i - 1];
		map[r + 1][i] = map[r + 1][i - 1];
	}
	map[r][c + 1] = 0;
	map[r + 1][c + 1] = 0;
}
int solve()
{
	int time = 0;
	while (time++ < T)
	{
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (map[i][j] != 0 && map[i][j] != -1)
				{
					q.push({ i, j });
					v.push(map[i][j]);
				}
			}
		}
		diffuse();
		work();
	}
	int sum = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] != 0 && map[i][j] != -1)
			{
				sum += map[i][j];
			}
		}
	}

	return sum;
}
int main()
{
	cin >> R >> C >> T;
	map.assign(R, vector<int>(C));

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == -1)
			{
				r = i;
				c = j;
			}
		}
	}
	r--;

	cout << solve() << "\n";
}