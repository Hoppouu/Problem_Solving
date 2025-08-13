//10:42
#include <iostream>
using namespace std;

int dp[1001];
int main()
{
    int n;
    cin >> n;

    int arr[3] = {1, 3, 4};

    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(i >= arr[j] && dp[i - arr[j]] == 0)
            {
                dp[i] = 1;
            }
        }
    }

    cout << (dp[n] ? "SK" : "CY") << '\n';
}