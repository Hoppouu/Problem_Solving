//15:56
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if(n < 0)
    {
        n *= -1;
    }
    int cnt = 0;
    if(n % 2 == 1)
    {
        while(n > 0)
        {
            n /= 2;
            cnt++;
        }
    }
    else
    {
        if(n != 0)
        {
            cnt = -1;
        }
    }
    cout << cnt << "\n";

}