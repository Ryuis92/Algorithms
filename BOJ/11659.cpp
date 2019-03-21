/* https://www.acmicpc.net/problem/11659 */

#include<iostream>
#include<vector>
#include<cmath>

#define MAX_SIZE 100000
using namespace std;

int level = int(ceil(log2(MAX_SIZE)) + 1);
int tree_size = 1 << level;
vector<long long> tree(tree_size);
long long arr[MAX_SIZE];
int n, m, k;

long long initTree(int node, int start, int end);
long long update(int node, long long diff, int cover_s, int cover_e, int update_s, int update_e);
long long query(int node, int cover_s, int cover_e, int find_s, int find_e);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	initTree(1, 0, n - 1);

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		cout << query(1, 0, n - 1, a - 1, b - 1) << "\n";
	}
	return 0;
}

long long initTree(int node, int start, int end) 
{
	if (start == end)
	{
		tree[node] = arr[start];
		return tree[node];
	}

	int mid = (start + end) / 2;

	long long left = initTree(node * 2, start, mid);
	long long right = initTree(node * 2 + 1, mid + 1, end);

	return tree[node] = left + right;
}

long long update(int node, long long diff, int cover_s, int cover_e, int update_s, int update_e) 
{
	if (update_e < cover_s || cover_e < update_s)
		return tree[node];

	if(cover_s == cover_e)
		return tree[node] += diff;
	
	int mid = (cover_s + cover_e) / 2;
	long long left = update(node * 2, diff, cover_s, mid, update_s, update_e);
	long long right = update(node * 2 + 1, diff, mid+1, cover_e, update_s, update_e);

	return tree[node] = left + right;
}

long long query(int node, int cover_s, int cover_e, int find_s, int find_e)
{
	if (find_e < cover_s || cover_e < find_s)
		return 0;

	if (find_s <= cover_s && cover_e <= find_e)
		return tree[node];

	int mid = (cover_s + cover_e) / 2;
	long long left = query(node * 2, cover_s, mid, find_s, find_e);
	long long right = query(node * 2 + 1, mid + 1, cover_e, find_s, find_e);

	return left + right;
}