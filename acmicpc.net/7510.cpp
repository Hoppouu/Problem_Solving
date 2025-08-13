//14:49
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int arr[3];
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr + 3);
        printf("Scenario #%d:\n", i + 1);
        if(arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2])
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
        cout << '\n';
    }
}