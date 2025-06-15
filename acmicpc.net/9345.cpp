#include <iostream>
#include <cmath>
#include <vector>
#define INF ((1 << 31) - 1)
using namespace std;
typedef pair<int, int> pii;

int t, n, m;
vector<int> v;
vector<pii> tree;

pii make_tree(int node, int start, int end)
{
	if (start == end)
	{
		tree[node].first = v[start];
		tree[node].second = v[start];
		return tree[node];
	}
	int mid = (start + end) / 2;
	pii left = make_tree(node * 2, start, mid);
	pii right = make_tree(node * 2 + 1, mid + 1, end);

	tree[node].first = min(left.first, right.first);
	tree[node].second = max(left.second, right.second);
	return tree[node];
}
pii query(int A, int B, int n, int l, int r)
{
	if (l > B || r < A)
	{
		return { INF, 0 };
	}
	if (l >= A && r <= B)
	{
		return tree[n];
	}
	int mid = (l + r) / 2;
	pii left = query(A, B, n * 2, l, mid);
	pii right = query(A, B, n * 2 + 1, mid + 1, r);

	pii p;
	p.first = min(left.first, right.first);
	p.second = max(left.second, right.second);
	return p;
}

pii update(int idx, int value, int n, int l, int r)
{
	if (idx < l || idx > r)
	{
		return tree[n];
	}
	else if (l == r)
	{
		tree[n].first = value;
		tree[n].second = value;
		v[idx] = value;
		return tree[n];
	}
	int mid = (l + r) / 2;
	pii left = update(idx, value, n * 2, l, mid);
	pii right = update(idx, value, n * 2 + 1, mid + 1, r);
	pii p;
	p.first = min(left.first, right.first);
	p.second = max(left.second, right.second);

	tree[n] = p;
	return tree[n];
}

void change(int a, int b)
{
	int t = v[a];
	update(a, v[b], 1, 0, n - 1);
	update(b, t, 1, 0, n - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	
	while (t--)
	{
		cin >> n >> m;
		v.assign(n + 1, 0);
		int h = ceil(log(n) / log(2));
		int size = 1 << (h + 1);
		tree.assign(size, pii(0, 0));
		for (int i = 0; i < n; i++)
		{
			v[i] = i;
		}
		make_tree(1, 0, n - 1);
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			if (a == 0)
			{
				change(b, c);
			}
			else if (a == 1)
			{
				int x = query(b, c, 1, 0, n - 1).first;
				int y = query(b, c, 1, 0, n - 1).second;
				if (b == x && c == y)
				{
					cout << "YES\n";
				}
				else
				{
					cout << "NO\n";
				}
			}
		}
	}

}