//17:05
#include <iostream>
using namespace std;
int main()
{
    string str;
    getline(cin, str);

    int sum = 0;
    int arr[4] = {0, 500, 800, 1000};

    for(int i = 0; i < str.length(); i++)
    {
        if(isdigit(str[i]))
        {
            sum += arr[str[i] - '0'];
        }
    }

    cout << 5000 - sum << '\n';
}