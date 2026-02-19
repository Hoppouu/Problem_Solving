#include <bits/stdc++.h>

using namespace std;
vector<vector<char>> grid;
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    grid.assign(n, vector<char>(m));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    char pre = 0;
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        pre = 0;
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == '-' && pre != '-')
            {
                res++;
            }
            pre = grid[i][j];
        }
    }
    for(int i = 0; i < m; i++)
    {
        pre = 0;
        for(int j = 0; j < n; j++)
        {
            if(grid[j][i] == '|' && pre != '|')
            {
                res++;
            }
            pre = grid[j][i];
        }
    }

    cout << res << "\n";
}