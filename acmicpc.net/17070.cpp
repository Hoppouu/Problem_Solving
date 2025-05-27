#include <iostream>
#include <vector>

using namespace std;
int n;
vector<vector<int>> map, used;

//0->가로, 1->세로, 2->대각선
int dr[3][3] =
{
	{0, 0, 1},
	{0, 1, 1},
	{0, 1, 1}
};
int dc[3][3] =
{
	{1, 0, 1},
	{0, 0, 1},
	{1, 0, 1}
};

bool check(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < n;
}

int cnt = 0;
void solve(int r, int c, int dir)
{
	if (r == n - 1 && c == n - 1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << used[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";

		cnt++;
	}
	for (int j = 0; j < 3; j++)
	{

		int nr = r + dr[dir][j], nc = c + dc[dir][j];
		if (dr[dir][j] == 0 && dc[dir][j] == 0)
		{
			continue;
		}

		if (check(nr, nc) && map[nr][nc] == 0 && !used[nr][nc])
		{
			if(j == 2 && !used[r + 1][c] && !used[r][c + 1])
			if (j == 2)
			{
				used[r + 1][c] = 1;
				used[r][c + 1] = 1;
			}
			used[nr][nc] = 1;
			solve(nr, nc, j);
			if (j == 2)
			{
				used[r + 1][c] = 0;
				used[r][c + 1] = 0;
			}
			used[nr][nc] = 0;
		}
	}
}
int main()
{
	cin >> n;
	map.assign(n, vector<int>(n));
	used.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	solve(0, 1, 0);

	cout << cnt << "\n";
}