//08:04
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;
	vector<string> v;
	cin >> n;
	cin.ignore();
	while (n--)
	{
		string x;
		getline(cin, x);
		v.push_back(x);
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << i + 1 << ". " << v[i] << "\n";
	}
}