#include <iostream>
#include <queue>
#include <vector>
#define INF (1 << 30)
using namespace std;

queue<char> var, op;
vector<int> priority;
void solve()
{
	
}

int main()
{
	string str;
	
	cin >> str;
	priority.assign(str.size(), INF);

	int mul = 1, plus = 2;
	for (int i = 0; i < str.size(); i++)
	{
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			var.push(str[i]);
		}
		else
		{
			if (str[i] == '*')
			{
				priority[i] = mul;
				op.push(str[i]);
			}
			else if(str[i] == '+')
			{
				priority[i] = plus;
				op.push(str[i]);
			}
			else if(str[i] == '(')
			{
				mul -= 2;
				plus -= 2;
			}
			else if (str[i] == ')')
			{
				mul += 2;
				plus += 2;
			}
		}
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (priority[i] != INF)
		{
			cout << priority[i] << " ";
		}
	}
	cout << "\n";
	while (!var.empty())
	{
		cout << var.front() << "\n"; var.pop();
	}

	while (!op.empty())
	{
		cout << op.front() << "\n"; op.pop();
	}
}

/*
A*(B+C)

A B C

* +

A*(B+C*D+E*F+G)
A * ( B + C * D + E * F + G )
  1       2    1    2    1    2
  1       0    -1   0   -1    0
B+{CD*}+{EF*} + G
ABCD*+EF*+G+*

ABCD*+EF*+G+*

*/