#include <iostream>
#include <cmath>
#include <vector>
#define INF (1 < 31)
using namespace std;
typedef pair<int, int> pii;

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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, h, size;
	cin >> n;

	h = ceil(log(n) / log(2));
	size = 1 << (h + 1);

	v.assign(n + 1, 0);
	tree.assign(size, pii(0, 0));
	for (int i = 0; i < n; i++)
	{
		v[i] = i + 1;
	}
	make_tree(1, 0, n - 1);
	for (int i = 1; i < size; i++)
	{
		cout << tree[i].first << "\t";
	}
	puts("");
	for (int i = 1; i < size; i++)
	{
		cout << tree[i].second << "\t";
	}
	for (int i = 0; i < 4; i++)
	{
			cout << "a\n";
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(b - 1, c, 1, 0, n - 1);
		}
		else if (a == 2)
		{
			cout << "a\n";
			cout << query(b - 1, c - 1, 1, 0, n - 1).first << " ";
			cout << query(b - 1, c - 1, 1, 0, n - 1).second << "\n";
		}
	}
}