//13:00
#include <iostream>
using namespace std;

#define MOD 1000000007

int n;
long long dp[1001];
int main()
{
    cin >> n;

    if(n % 2 == 1)
    {
        cout << 0 << '\n';
        return 0;
    }

    dp[0] = 1;
    for(int i = 2; i <= n; i += 2)
    {
        dp[i] = dp[i - 2] * 3;
        for(int j = 4; j <= i; j += 2)
        {
            dp[i] += dp[j - 4] * 2;
            dp[i] %= MOD;
        }
    }
    cout << dp[n] << '\n';
}