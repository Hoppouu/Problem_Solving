#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{
    cin >> n;

    while(n--)
    {
        int x;
        cin >> x;

        priority_queue<int, vector<int>, less<int>> q1;
        priority_queue<int, vector<int>, greater<int>> q2;
        unordered_map<int, int> m;

        while(x--)
        {
            char ch;
            cin >> ch;
            if(ch == 'I')
            {
                int xx;
                cin >> xx;
                q1.push(xx);
                q2.push(xx);
                m[xx]++;
            }
            else if(ch == 'D')
            {
                int xx;
                cin >> xx;
                if(xx > 0)
                {
                    if(!q1.empty())
                    {
                        m[q1.top()]--;
                        q1.pop();
                    }
                }
                else if(xx < 0)
                {
                    if(!q2.empty())
                    {
                        m[q2.top()]--;
                        q2.pop();
                    }
                }
            }
            
            while(!q1.empty() && m[q1.top()] == 0)
            {
                q1.pop();
            }
            while(!q2.empty() && m[q2.top()] == 0)
            {
                q2.pop();
            }
        }
        if(q1.empty())
        {
            cout << "EMPTY\n";
        }
        else
        {
            cout << q1.top() << " " << q2.top() << "\n";
        }
    }
}