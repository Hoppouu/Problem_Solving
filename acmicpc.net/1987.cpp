#include <iostream>
#include <vector>

using namespace std;

vector<string> map;
vector<int> used;
int n, m;
int cnt, max_cnt;

bool check(int r, int c)
{
    return 0 <= r && r < n && 0 <= c && c < m;
}

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
void solve(int r, int c)
{
    used[map[r][c] - 'A'] = 1;
    cnt++;
    int f = true;
    int init = cnt;
    for(int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(check(nr, nc) && !used[map[nr][nc] - 'A'])
        {
            f = false;
            solve(nr, nc);
            used[map[nr][nc] - 'A'] = 0;
            cnt = init;
        } 
    }
    if(f)
    {
        max_cnt = max(cnt , max_cnt);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    map.assign(n, string());
    used.assign(26, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> map[i];
    }
    solve(0, 0);
    cout << max_cnt << "\n";
}