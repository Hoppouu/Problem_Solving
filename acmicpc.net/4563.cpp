#include <iostream>
using namespace std;

int T, a;

int solve()
{
    // c = A / (2 * t) + t / 2
    // b = A / (2 * t) - t / 2
    // t는 2의 배수 이어야함.
    int A = a * a;
    
    for(int t = 2; t < a; t++)
    {
        int c = A / (2 * t) + t / 2;
        int b = A / (2 * t) - t / 2;
        
    }
}
int main()
{
    cin >> T;
    while(T--)
    {
        cin >> a;

    }
}