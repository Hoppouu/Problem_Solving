//15:56
#include <iostream>
#include <vector>
#include <queue>

#define N 8
#define NUM_DIRECTION 9

using namespace std;

vector<string> map;
vector<vector<bool>> used;

queue<pair<int, int>> q;

int dr[NUM_DIRECTION] = { 0, 1, -1, 0, 0, 1, 1, -1, -1 };
int dc[NUM_DIRECTION] = { 0, 0, 0, 1, -1, 1, -1, 1, -1 };

//int dr[NUM_DIRECTION] = { 0, 1, 0, 1};
//int dc[NUM_DIRECTION] = { 0, 0, 1, 1};

bool check(int r, int c)
{
	return 0 <= r && r < N && 0 <= c && c < N;
}

bool f;
int canIGo()
{
	int size = q.size();
	for (int k = 0; k < size; k++)
	{
		int r = q.front().first, c = q.front().second; q.pop();
		used[r][c] = false;
		if (r == 0 && c == N - 1)
		{
			f = true;
			return true;
		}

		for (int i = 0; i < NUM_DIRECTION; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
		
			if (check(nr, nc) && !used[nr][nc] && map[nr][nc] == '.')
			{
				q.push({ nr, nc });
				used[nr][nc] = true;
			}
		}
	}

	if (q.empty())
	{
		return false;
	}

	return true;
}

void tick()
{
	for (int i = N - 1; i >= 0; i--)
	{
		int ni = i + 1;
		for (int j = N - 1; j >= 0; j--)
		{
			int size = q.size();
			int r, c;
			for (int k = 0; k < size; k++)
			{
				r = q.front().first, c = q.front().second; q.pop();
				if (check(ni, j) && map[i][j] == '#' && ni == r && j == c)
				{
					used[r][c] = false;
					continue;
				}
				q.push({ r, c });
			}

			if (check(ni, j) && map[i][j] == '#' && map[ni][j] == '.')
			{
				map[i][j] = '.';
				map[ni][j] = '#';
			}
			else if (!check(ni, j) && map[i][j] == '#')
			{
				map[i][j] = '.';
			}
		}
	}
}

void solve()
{
	used.assign(N, vector<bool>(N, false));
	//가장 왼쪽 아랫 칸
	q.push({ N - 1, 0 });

	while (!q.empty())
	{
		f = false;
		if (!canIGo())
		{
			cout << "0";
			return;
		}
		if (f)
		{
			cout << "1\n";
			return;
		}
		tick();

	}

	cout << "0\n";
}

int main()
{
	for (int i = 0; i < N; i++)
	{
		string line;
		cin >> line;
		map.push_back(line);
	}
	solve();
}