/* https://www.acmicpc.net/problem/1967 */
#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

#define child first 
#define weight second 

int inorder(vector<pair<int, int>>* tree, int root, int total);
int findMax(vector<pair<int, int>>* tree, int root);

int main()
{
	int n;
	vector<pair<int, int>>* tree;
	scanf("%d", &n);
	tree = new vector<pair<int, int>>[n + 1];
	int pa, ch, w;


	for (int i = 1; i < n; i++)
	{
		scanf("%d %d %d", &pa, &ch, &w);
		tree[pa].push_back(make_pair(ch, w));
	}

	printf("%d\n", findMax(tree, 1));

	delete[] tree;

	return 0;
}

int inorder(vector<pair<int, int>>* tree, int root, int total) 
{
	if (tree[root].size() == 0)
		return total;

	int ans = 0;
	for (int i = 0; i < tree[root].size(); i++)
		ans = max(ans, inorder(tree, tree[root][i].child, total + tree[root][i].weight));

	return ans;
}

int findMax(vector<pair<int, int>>* tree, int root)
{
	int child_num = tree[root].size();
	int ans;
	vector<int> res;

	if (child_num == 0)
		return 0;

	for (int i = 0; i < child_num; i++)
		res.push_back(inorder(tree, tree[root][i].child, tree[root][i].weight));
	
	if (child_num != 1)
	{
		sort(res.begin(), res.end());
		ans = res[child_num - 1] + res[child_num - 2];
	}
	else
		ans = res[child_num - 1];

	for (int i = 0; i < child_num; i++)
		ans = max(ans, findMax(tree, tree[root][i].child));

	
	return ans;
}