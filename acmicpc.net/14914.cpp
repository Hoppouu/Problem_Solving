//14:06
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    while(b != 0)
    {
        int t = a;
        a = b;
        b = a % b; 
    }
    return a;
}
int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= gcd(n, m); i++)
    {
        if(n % i == 0 && m % i == 0)
        {
            cout << i << ' ' << n / i << ' ' << m / i << '\n';
        }
    }
}