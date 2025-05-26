#include <iostream>
using namespace std;

int T, a;

int solve()
{
    // c = A / (2 * t) + t / 2
    // b = A / (2 * t) - t / 2
    // t는 2의 배수 이어야함.
    int A = a * a;
    int cnt = 0;
    //c > a + b 이어야한다.
    for(int t = 2; t < a * a; t++)
    {
        if(A % (2 * t) != 0)
        {
            continue;
        }
        int c = A / (2 * t) + t / 2;
        int b = A / (2 * t) - t / 2;
        if(c > b + c)
        {
            cout << a << " " << b << " " << c << "\n";
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    cin >> T;
    while(T--)
    {
        cin >> a;
        cout << solve() << "\n";
    }
}