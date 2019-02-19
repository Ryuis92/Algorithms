/* https://www.acmicpc.net/problem/1991 */

#include<iostream>
#include<cstdio>
using namespace std;
#define LEFT  0
#define RIGHT 1 

void inorder(char root, char tree[][26]);
void preorder(char root, char tree[][26]);
void postorder(char root, char tree[][26]);

int main() 
{
	char tree[2][26];
	int n;
	char root;
	char left, right;
	cin >> n;
	
	for(int i = 0; i<sizeof(tree)/sizeof(tree[0]); i++)
		for (int j = 0; j < sizeof(tree[i]) / sizeof(tree[i][0]); j++)
		{
			tree[i][j] = -1;
		}

	for (int i = 0; i < n; i++)
	{
		cin >> root;

		cin >> left >> right; 
		if (left != '.')
			tree[LEFT][root - 'A'] = left;
		if (right != '.')
			tree[RIGHT][root - 'A'] = right;
	}

	/*
	for (int i = 0; i < sizeof(tree[0]) / sizeof(tree[0][0]); i++)
		printf("root: %c, left: %c, right: %c\n", 'A'+(char)i, tree[LEFT][i], tree[RIGHT][i]);
	*/

	preorder('A', tree);
	cout << endl;

	inorder('A', tree);
	cout << endl;

	postorder('A', tree);
	cout << endl;
	return 0;
}

void inorder(char root, char tree[][26]) 
{
	if (root == -1)
		return;

	inorder(tree[LEFT][root - 'A'] , tree);
	cout << root;
	inorder(tree[RIGHT][root - 'A'], tree);
}

void preorder(char root, char tree[][26])
{
	if (root == -1)
		return;

	cout << root;
	preorder(tree[LEFT][root - 'A'], tree);
	preorder(tree[RIGHT][root - 'A'], tree);
}
void postorder(char root, char tree[][26])
{
	if (root == -1)
		return;

	postorder(tree[LEFT][root - 'A'] ,tree);
	postorder(tree[RIGHT][root - 'A'],tree);
	cout << root;
}