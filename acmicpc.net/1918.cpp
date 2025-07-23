//13:45
#include <iostream>
#include <stack>
using namespace std;
stack<char> s;

int priority(char ch)
{
	if (ch == '+' || ch == '-')
	{
		return 1;
	}
	else if (ch == '*' || ch == '/')
	{
		return 2;
	}

	return 0;
}

int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			cout << str[i];
			continue;
		}
		else if (str[i] == '(')
		{
			s.push(str[i]);
			continue;
		}
		else if (str[i] == ')')
		{
			while (s.top() != '(')
			{
				cout << s.top(); s.pop();
			}
			s.pop();
			continue;
		}

		if (s.empty())
		{
			s.push(str[i]);
		}
		else if (priority(str[i]) > priority(s.top()))
		{
			s.push(str[i]);
		}
		else if (priority(str[i]) <= priority(s.top()))
		{
			while (!s.empty() && priority(str[i]) <= priority(s.top()))
			{
				cout << s.top(); s.pop();
			}
			s.push(str[i]);
		}
	}

	while (!s.empty())
	{
		cout << s.top(); s.pop();
	}
}

/*
A*(B+C*D+E*F+G)

ABCD*+EF*+G+*
*/