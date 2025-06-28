//19:51
#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] += 32;
			}
		}
		cout << str << "\n";
	}

}