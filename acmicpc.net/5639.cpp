#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int data;
	node* parent = NULL;
	node* left = NULL;
	node* right = NULL;
}typedef node;

node* head;

void input(int x)
{
	if (head == NULL)
	{
		head = new node;
		head->data = x;
		return;
	}
	
	node* current = head;
	node* parent = NULL;
	while (current != NULL)
	{
		parent = current;
		if (x < current->data)
		{
			current = current->left;
		}
		else if (x > current->data)
		{
			current = current->right;
		}
	}

	node* t = new node;
	t->data = x;
	t->parent = parent;

	if (x < parent->data)
	{
		parent->left = t;
	}
	else if (x > parent->data)
	{
		parent->right = t;
	}
}

void order_pre(node* head)
{
	if (head == NULL)
	{
		return;
	}
	order_pre(head->left);
	order_pre(head->right);
	cout << head->data << "\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int x;
	while (cin >> x)
	{
		input(x);
	}
	order_pre(head);
}