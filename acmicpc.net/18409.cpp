#include <iostream>
using namespace std;
int main()
{
    int n;
    string str;
    cin >> n >> str;
    int cnt = 0;
    char t[5] = {'a', 'i', 'e', 'o', 'u'};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(str[i] == t[j])
            {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
}