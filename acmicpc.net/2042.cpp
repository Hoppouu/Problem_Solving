#include <iostream>
#include <cmath>
#include <vector>
typedef long long ll;
using namespace std;

vector<ll> v, tree;
ll make_tree(int node, int start, int end)
{
	if (start == end)
	{
		tree[node] = v[start];
		return tree[node];
	}
	int mid = (start + end) / 2;
	ll left = make_tree(node * 2, start, mid);
	ll right = make_tree(node * 2 + 1, mid + 1, end);

	tree[node] = left + right;
	return tree[node];
}
ll query(int A, int B, int n, int l, int r)
{
	if (l > B || r < A)
	{
		return 0;
	}
	if (l >= A && r <= B)
	{
		return tree[n];
	}
	int mid = (l + r) / 2;
	return query(A, B, n * 2, l, mid) + query(A, B, n * 2 + 1, mid + 1, r);
}

ll update(int idx, ll value, int n, int l, int r)
{
	if (idx < l || idx > r)
	{
		return tree[n];
	}
	else if (l == r)
	{
		tree[n] = value;
		return value;
	}
	int mid = (l + r) / 2;
	tree[n] = update(idx, value, n * 2, l, mid) + update(idx, value, n * 2 + 1, mid + 1, r);
	return tree[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k, h, size;
	cin >> n >> m >> k;

	h = ceil(log(n) / log(2));
	size = 1 << (h + 1);

	v.assign(n + 1, 0);
	tree.assign(size, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	make_tree(1, 0, n - 1);

	for (int i = 0; i < m + k; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(b - 1, c, 1, 0, n - 1);
		}
		else if (a == 2)
		{
			cout << query(b - 1, c - 1, 1, 0, n - 1) << "\n";
		}
	}
}