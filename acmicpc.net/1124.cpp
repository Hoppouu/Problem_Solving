#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime;
vector<int> prime;
vector<int> memo;
int solve(int x)
{
    int cnt = 0;
    int t = x;
    for(int i = 0; i < prime.size(); i++)
    {
        int item = prime[i];
        if(item * item > x)
        {
            break;
        }

        while(x % item == 0)
        {
            if(memo[x] != 0)
            {
                cnt += memo[x];
                x = 1;
                break;
            }
            cnt++;
            x /= item;
        }
    }
    if(x > 1)
    {
        cnt++;
    }
    if(memo[t] == 0)
    {
        memo[t] = cnt;
    }

    return memo[t];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int A, B;

    cin >> A >> B;

    isPrime.assign(B + 1, true);
    memo.assign(B + 1, 0);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i <= B; i++)
    {
        if(!isPrime[i]) continue;
        for(int j = i + i; j <= B; j += i)
        {
            isPrime[j] = false;
        }
    }
    for(int i = 2; i <= B; i++)
    {
        if(isPrime[i])
        {
            prime.push_back(i);
        }
    }

    int cnt = 0;
    for(int i = A; i <= B; i++)
    {
        if(isPrime[solve(i)])
        {
            cnt++;
        }
    }

    cout << cnt << "\n";
}