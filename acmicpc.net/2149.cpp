#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
string key, msg;
using zip = struct zip
{
    char ch;
    int id;
    vector<char> list;
};

bool compareA(zip z1, zip z2)
{
    return z1.ch < z2.ch;
}

bool compareB(zip z1, zip z2)
{
    return z1.id < z2.id;
}

int main()
{
    cin >> key >> msg;
    vector<zip> z(key.length());
    vector<zip> zz(key.length());
    
    for(int i = 0; i < key.length(); i++)
    {
        z[i].ch = key[i];
        z[i].id = i;
    }

    sort(z.begin(), z.end(), compareA);
    
    int size = msg.length() / key.length();
    for(int i = 0; i < key.length(); i++)
    {
        for(int j = 0; j < size; j++)
        {
            int k = i * size + j;
            z[i].list.push_back(msg[k]);
        }
    }
    sort(z.begin(), z.end(), compareB);
    for(int i = 0; i < msg.length() / key.length(); i++)
    {
        for(int j = 0; j < key.length(); j++)
        {
            cout << z[j].list[i];
        }
    }
}