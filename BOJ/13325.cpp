/* https://www.acmicpc.net/problem/13325 */

/*Top down approach*/
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>

using namespace std;
int level;
int tree_size;
long long sum = 0;
pair<long long, pair<int, int>>* tree;
long long dfs(int root);
void update(int root, long long max_val);

int main()
{
	scanf("%d", &level);
	
	tree_size = (1 << level);
	tree = new pair<long long, pair<int, int>>[tree_size];
	
	//init tree
	queue<int> q;
	q.push(1);
	int p;
	int left, right;
	while (!q.empty())
	{
		p = q.front(); q.pop();
		scanf("%d %d", &left, &right);
		
		tree[p].first = 0;

		tree[p].second.first = left;
		tree[p].second.second = right;

		sum += left;
		sum += right;

		if (2 * p < tree_size)
		{
			q.push(p * 2);
			q.push(p * 2 + 1);
		}
	}
	
	//find max
	dfs(1);
	//for (int i = 1; i < tree_size; i++)
	//	printf("%d node: left:%d, right: %d, max: %lld\n", i, tree[i].second.first, tree[i].second.second, tree[i].first);

	//update
	update(1, tree[1].first);
	//for (int i = 1; i < tree_size; i++)
	//	printf("%d node: left:%d, right: %d, max: %lld\n", i, tree[i].second.first, tree[i].second.second, tree[i].first);
	printf("%lld\n", sum);
	return 0;
}
long long dfs(int root)
{
	if (root > tree_size - 1)
		return 0;

	long long left = dfs(2 * root) + tree[root].second.first;
	long long right = dfs(2 * root + 1) + tree[root].second.second;
	tree[root].first = max(left, right);

	return tree[root].first;
}

void update(int root, long long max_val)
{
	if (root > tree_size - 1)
		return;

	long long left;
	long long right;

	if (root * 2 < tree_size)
	{
		left = tree[root * 2].first + tree[root].second.first;
		right = tree[root * 2 + 1].first + tree[root].second.second;
	}
	else
	{
		left = tree[root].second.first;
		right = tree[root].second.second;
	}

	tree[root].second.first += (max_val - left);
	tree[root].second.second += (max_val - right);

	sum += (max_val - left + max_val - right);

	update(root * 2, max_val - tree[root].second.first);
	update(root * 2 + 1, max_val -tree[root].second.second);
}

/*Down top approach*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 1 << 21;
int N, treeSize;
int result;
int arr[MAX];

int DFS(int idx)
{
    if (idx * 2 >= treeSize)
    {
    	/*if leaf node*/
        result += arr[idx];
        
        return arr[idx];
    }
    else
    {
    	/*if not leaf node, which means having subtree*/
	    int leftNode = DFS(idx * 2);
	    int rightNode = DFS(idx * 2 + 1);
	    /*by adding the difference of two subtrees, it works as incrementing edge weight*/
	    result += arr[idx] + abs(leftNode - rightNode);

	    return arr[idx] + max(leftNode, rightNode);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    treeSize = 1 << (N + 1);

    for (int i = 2; i < treeSize; i++)
        cin >> arr[i];

    DFS(1);

    cout << result << "\n";

    return 0;
}