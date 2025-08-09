//17:23
#include <iostream>
using namespace std;

int n, k;
int solve(int n, int k)
{
    if (k % 2 == 0)
    {
        return ((n / k) + (n / k + 1)) * (k / 2);
    }
    else
    {
        return ((n / k - 1) + (n / k + 1)) * (k / 2) + (n / k);
    }
}

int get_start(int n, int k)
{
    if (k % 2 == 0)
    {
        return n / k - k / 2 + 1;
    }
    else
    {
        return n / k - k / 2;
    }

}

int main() {
    cin >> n >> k;
    bool f = true;
    for (int i = k; i <= 100; i++)
    {
        if (solve(n, i) == n)
        {
            int t = get_start(n, i);
            if (t < 0)
            {
                continue;
            }
            f = false;
            for (int j = 0; j < i; j++)
            {
                cout << t + j << " ";
            }
            cout << '\n';
            break;
        }
    }

    if (f)
    {
        cout << -1 << '\n';
    }
    return 0;
}