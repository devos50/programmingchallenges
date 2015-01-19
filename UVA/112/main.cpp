/* Tree Summing */
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctype.h>

using namespace std;

typedef struct Node {
	int val;
	struct Node *left;
	struct Node *right;
} Node;

int sum_tree(int n, Node *t)
{
	if (t == NULL) return 0;
	else if (n == t->val && !t->left && !t->right) return 1;
	else return sum_tree(n-(t->val), t->left) || sum_tree(n-(t->val), t->right);
}

Node *create_tree()
{
	int a;
	Node *result;

	a = getc(stdin);
	while(isspace(a)) a = getc(stdin);
	
	a = getc(stdin);
	while(isspace(a)) a = getc(stdin);
	if (a == ')') return NULL;
	ungetc(a, stdin);
	
	cin >> a;
	
	result = new Node();
	result->val = a;
	result->left = create_tree();
	result->right = create_tree();
	a = getc(stdin);
	while(isspace(a)) a = getc(stdin);
	
	return result;
}

int main()
{
	int sum;
	Node *node;
	while(true) 
	{
		if (!(cin >> sum)) break;
		node = create_tree();
		if (sum_tree(sum, node)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}