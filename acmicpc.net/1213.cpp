//13:22
#include <iostream>
#include <algorithm>
using namespace std;
int cnt[26];

int main()
{
    string str;
    cin >> str;

    for(unsigned int i = 0; i < str.length(); i++)
    {
        cnt[str[i] - 'A']++;
    }
    int cnt_odd = 0, cnt_even = 0;
    for(int i = 0; i < 26; i++)
    {
        if(cnt[i] % 2 == 0)
        {
            cnt_even++;
        }
        else
        {
            cnt_odd++;
        }
    }
    if(str.length() % 2 == 0)
    {
        if(cnt_odd >= 1)
        {
            cout << "I'm Sorry Hansoo\n";
            return 0;
        }
    }
    else
    {
        if(cnt_odd >= 2)
        {
            cout << "I'm Sorry Hansoo\n";
            return 0;
        }
    }

    string str2 = "";
    string t = "";
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < cnt[i] / 2; j++)
        {
            str2 += 'A' + i;
        }
        if(cnt[i] % 2 == 1)
        {
            t += 'A' + i;
        }
    }

    cout << str2 << t;
    reverse(str2.begin(), str2.end());
    cout << str2 << '\n';
}