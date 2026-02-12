#include <iostream>
#include <string>
using namespace std;
string s, t;
int main()
{
    while(cin >> s >> t)
    {
        int i = 0, j = 0;
        while(i < s.length() && j < t.length())
        {
            if(s[i] == t[j])
            {
                i++; j++;
            }
            else
            {
                j++;
            }
        }
        if(i == s.length())
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

}