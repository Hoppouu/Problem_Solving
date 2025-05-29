#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int n, m;
void solve(int x)
{
    q.push({0, x});

    while(!q.empty())
    {
        int cur = q.top().second;
        for(int i = 0; i < graph[cur].size(); i++)
        {
            
        }
    }
}

int main()
{
    cin >> n >> m;
    graph.assign(n + 1, vector<int>());
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    int a, b;
    cin >> a >> b;
}