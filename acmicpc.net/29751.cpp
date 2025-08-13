//13:56
#include <iostream>
using namespace std;
int main()
{
    cout << fixed;
    cout.precision(1);
    int w, h;
    cin >> w >> h;
    cout << w * h / 2.0;
}