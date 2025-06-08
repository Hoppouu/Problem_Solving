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
	else if (l == r && l == idx)
	{
		tree[n] = value;
		return value;
	}
	int mid = (l + r) / 2;
	return tree[n] = update(idx, value, n * 2, l, mid) + update(idx, value, n * 2 + 1, mid + 1, r);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K, height, tree_size;
	cin >> N >> M >> K;
	height = ceil(log(N) / log(2));
	tree_size = 1 << (height + 1);

	v.assign(N + 1, 0);
	tree.assign(tree_size, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	make_tree(1, 0, N - 1);

	for (int i = 0; i < M + K; i++)
	{
		ll x, a, b;
		cin >> x >> a >> b;
		if (x == 2)
		{
			cout << query(a - 1, b - 1, 1, 0, N - 1) << "\n";
		}
		else if (x == 1)
		{
			update(a - 1, b, 1, 0, N - 1);
		}
	}
}