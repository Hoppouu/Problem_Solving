#include <iostream>
using namespace std;

long long a;

int solve()
{
    // c = A / (2 * t) + t / 2
    // b = A / (2 * t) - t / 2
    long long A = a * a;
    int cnt = 0;
    //c < a + b 이어야한다.
    for (int t = 1; t < a; t++)
    {
        long long c = A / t + t;
        long long b = A / t - t;
        if (A % t != 0 || c % 2 != 0 || b % 2 != 0)
        {
            continue;
        }
        c /= 2;
        b /= 2;
        if (c < a + b && b > a)
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    while (true)
    {
        cin >> a;
        if (a == 0)
        {
            break;
        }
        cout << solve() << "\n";
    }
}