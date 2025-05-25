#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> can;
vector<vector<pair<int, int>>> cnt;
int solve()
{
    int sum = 0;
    for(int i = cnt.size() - 1; i >= 0; i--)
    {
        for(int j = 0; j < cnt[i].size(); j++)
        {
            int r = cnt[i][j].first;
            int c = cnt[i][j].second;
            if(can[r][c])
            {
                int dr[4] = { 1, -1, 0, 0};
                int dc[4] = { 0, 0, 1, -1};
                for(int k = 0; k < 4; k++)
                {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >= 0 && nr < 2 && nc >= 0 && nc < n)
                    {
                        can[nr][nc] = 0;
                    }
                }
                sum += i;
            }
        }
    }
    return sum;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        cnt.assign(101, vector<pair<int, int>>());
        can.assign(2, vector<int>(n, 1));
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int x;
                cin >> x;
                cnt[x].push_back({i, j});
            }
        }
        cout << solve() << "\n";
    }
}