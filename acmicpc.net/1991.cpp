#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
void pre(int x)
{
    if(x == -1)
    {
        return;
    }

    cout << char(x + 'A');
    pre(v[x][0]);
    pre(v[x][1]);
}
void in(int x)
{
    if(x == -1)
    {
        return;
    }

    in(v[x][0]);
    cout << char(x + 'A');
    in(v[x][1]);
}
void post(int x)
{
    if(x == -1)
    {
        return;
    }
    post(v[x][0]);
    post(v[x][1]);
    cout << char(x + 'A');
}

void solve()
{
    pre(0);
    puts("");
    in(0);
    puts("");
    post(0);
}
int main()
{
    int n;
    cin >> n;
    v.assign(n + 1, vector<int>(2, -1));
    for(int i = 0; i < n; i++)
    {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;

        if(s2!= ".")
        {
            v[s1[0] - 'A'][0] = s2[0] - 'A';
        }
        if(s3 != ".")
        {
            v[s1[0] - 'A'][1] = s3[0] - 'A';
        }
    }
    solve();
}