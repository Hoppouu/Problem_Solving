#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


vector<int> v, tree;
int make_tree(int node, int start, int end)
{
	if (start == end)
	{
		tree[node] = v[start];
		return tree[node];
	}
	int mid = (start + end) / 2;
	int left = make_tree(node * 2, start, mid);
	int right = make_tree(node * 2 + 1, mid + 1, end);
	
	tree[node] = left + right;
	return tree[node];
}
int query(int A, int B, int n, int l, int r)
{
	if(l > B || r < A)
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

void update(int idx, int value, int n, int l, int r)
{
	if (idx < l || idx > r || l == r)
	{
		return;
	}
	tree[n] = tree[n] + value;
	int mid = (l + r) / 2;
	update(idx, value, n * 2, l, mid);
	update(idx, value, n * 2 + 1, mid + 1, r);
	
}
int main()
{
	int N, M, K, height, tree_size;
	cin >> N >> M >> K;
	height = ceil(log(N) / log(2));
	tree_size = 1 << (height + 1);

	v.assign(N + 1, 0);
	tree.assign(tree_size, 0);

	for (int i = 1; i <= N; i++)
	{
		int x;
		cin >> x;
		v[i] = x;
	}
	make_tree(1, 0, N);

	for (int i = 0; i < M + K; i++)
	{
		int x;
		cin >> x;
		if (x == 2)
		{
			int a, b;
			cin >> a >> b;
			cout << query(a, b, 1, 0, N) << "\n";
		}
	}
}