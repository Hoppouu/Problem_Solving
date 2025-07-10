//11:29
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, char> map;

int main()
{
	string code;
	cin >> code;
	vector<string> key;
	int n;
	cin >> n;
	while (n--)
	{
		string x;
		cin >> x;
		key.push_back(x);
	}

	string decode;
	for (char i = 'a' - 'a'; i <= 'z' - 'a'; i++)
	{
		decode = "";
		for (int j = 0; j < code.size(); j++)
		{
			decode.push_back('a' + (code[j] - 'a' + i) % ('z' - 'a' + 1));
		}
		for (int i = 0; i < key.size(); i++)
		{
			if (decode.find(key[i]) != string::npos)
			{
				cout << decode << "\n";
				return 0;
			}
		}
	}
}