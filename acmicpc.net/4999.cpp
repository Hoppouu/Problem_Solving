//20:20
#include <iostream>
using namespace std;
int main()
{
	string a, b;

	cin >> a >> b;
	
	cout << (a.length() >= b.length() ? "go" : "no") << "\n";
}