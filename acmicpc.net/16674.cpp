//15:29
#include <iostream>
using namespace std;

int cnt[10];
int main()
{
    int n;
    cin >> n;
    int remain = 0;
    while(n != 0)
    {
        int t = n % 10;
        cnt[t]++;
        if(!(t == 2 || t == 0 || t == 1 || t == 8))
        {
            remain++;
        }
        n /= 10;
    }
    if(!remain && (cnt[2] || cnt[0] || cnt[1] || cnt[8]))
    {
        if(cnt[2] && cnt[0] && cnt[1] && cnt[8])
        {
            int t = cnt[2];
            if(cnt[2] == t && cnt[0] == t && cnt[1] == t && cnt[8] == t)
            {
                cout << "8\n";
            }
            else
            {
                cout << "2\n";
            }
        }
        else
        {
            cout << "1\n";
        }
    }
    else
    {
        cout << "0\n";
    }
}