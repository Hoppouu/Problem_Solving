#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    v.assign(n, 0);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());
    
    int res = 0;
    for(int i = 0; i < n - 2; i++)
    {
        if(v[i] < v[i + 1] + v[i + 2])
        {
            res = v[i] + v[i + 1] + v[i + 2];
            break;
        }
    }

    cout << (res == 0 ? -1 : res) << "\n";
}