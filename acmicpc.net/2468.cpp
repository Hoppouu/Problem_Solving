#include <iostream>
#include <vector>
using namespace std;

int n, max_n;
vector<vector<int>> map;
vector<vector<bool>> used;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

bool check(int r, int c)
{
    return 0 <= r && r < n && 0 <= c && c < n;
}

bool f;
void dfs(int r, int c)
{
    if(used[r][c] || map[r][c] <= 0)
    {
        return;
    }
    used[r][c] = true;
    f = true;

    for(int k = 0; k < 4; k++)
    {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if(check(nr, nc) && !used[nr][nc] && map[nr][nc] > 0)
        {
            dfs(nr, nc);
        }
    }
}

void sol()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            map[i][j]--;
        }
    }
}
void solve()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int max_c = 0;
    for(int i = 0; i < max_n; i++)
    {
        if(i >= 1)
        {
            sol();
        }
        int c = 0;
        used.assign(n, vector<bool>(n, false));

        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                f = false;
                dfs(j, k);
                if(f)
                {
                    c++;
                }
            }
        }
        max_c = max(c, max_c);
    }

    cout << max_c << "\n";
}

int main()
{
    cin >> n;
    map.assign(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if(max_n < map[i][j])
            {
                max_n = map[i][j];
            }
        }
    }

    solve();
}