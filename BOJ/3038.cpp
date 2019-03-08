/* https://www.acmicpc.net/problem/3038 */

#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int* tree = new int[2];
int* new_tree;
int tree_size = 2;

void preorder(int root)
{
	if (root >= tree_size)
		return;

	printf("%d ", tree[root]);

	preorder(root * 2);
	preorder(root * 2 + 1);
}

void l_subtree(int idx, int nidx, int in)
{
	if (nidx >= tree_size)
		return;

	if (idx <= in)
		new_tree[nidx] = 2 * tree[idx];
	else
		new_tree[nidx] = 2 * tree[idx] + 1;

	l_subtree(idx * 2, nidx * 2, in);
	l_subtree(idx * 2 + 1, nidx * 2 + 1, in);
}

void r_subtree(int idx, int nidx, int in) 
{
	if (nidx >= tree_size)
		return;

	if (idx <= in)
		new_tree[nidx] = 2 * tree[idx] + 1;
	else
		new_tree[nidx] = 2 * tree[idx];

	r_subtree(idx * 2, nidx * 2, in);
	r_subtree(idx * 2 + 1, nidx * 2 + 1, in);
}

int main()
{
	int level;
	scanf("%d", &level);
	
	tree[0] = 0;
	tree[1] = 1;

	int curr = 1;

	while (curr < level)
	{
		curr++;
		tree_size = 1 << curr;
		int leaf, in;
		
		leaf = tree_size / 4;
		in = tree_size / 2 - 1 - leaf;
		in = max(1, in);

		new_tree = new int[tree_size];
		new_tree[1] = 1;

		//make left
		int idx = 1;
		int nidx = 2;
		l_subtree(idx, nidx, in);

		//make right
		idx = 1;
		nidx = 3;
		r_subtree(idx, nidx, in);

		delete tree;
		tree = new_tree;
	}
	
	preorder(1);
	delete tree;

	return 0;
}

/*
we can build a tree of level L from a tree of level L-1 that satisfies the conditions.
Let's say there's tree of level L-1 and its root is 1. We can build a tree of level L rooted at 1.

How to:
1. making left subtree. multiply 2 to leaf nodes and multiply 2 and add 1 to internal nodes of the level L - 1 tree.
2. making right subtree. multiply 2 and add 1 to leaf nodes and multiply 2 to internal nodes of the level L - 1 tree.
3. link these two subtree to root 1.

Why does it work?
1. the meaning of mutiplying 2. 
Each node of level d, the difference of its subtrees must be 2^d. Let's assume these's a tree that satisfies this condition. 
If you take steps above, you will multiply 2 to subtrees which will make the difference 2^d+1.

2. the meaning of adding 1.
Before to start, you have to know that in full binary tree of level L, thers 2^L leaf nodes, and 2^L - 1 internal nodes. So if you add 1 to internal nodes and leaf nodes of subtrees will make difference of 1.
This will make the tree satisfy the root condition.
*/