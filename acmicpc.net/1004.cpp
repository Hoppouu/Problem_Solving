#include <bits/stdc++.h>
using namespace std;
using point2 = pair<int, int>;

double getDist(point2 a, point2 b)
{
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    int sd = dx * dx + dy * dy;

    return sqrt(sd);
}

int main()
{
    int n;
    cin >> n;
    point2 start, end;
    int m;


    while(n--)
    {
        int cnt = 0;
        cin >> start.first >> start.second >> end.first >> end.second;
        cin >> m;
        while(m--)
        {
            point2 p;
            int r;
            cin >> p.first >> p.second >> r;
            double sDist = getDist(start ,p);
            double eDist = getDist(end, p);
            if(!(sDist <= r && eDist <= r))
            {
                if(sDist <= r || eDist <= r)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
}