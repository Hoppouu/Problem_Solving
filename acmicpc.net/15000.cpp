#include <iostream>
using namespace std;

int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		str[i] -= 32;
	}
	cout << str << "\n";
}