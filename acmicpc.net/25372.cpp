#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;

		if (str.length() >= 6 && str.length() <= 9)
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}
}