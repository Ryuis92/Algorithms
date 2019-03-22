/* https://www.acmicpc.net/problem/11658 */

#include<iostream>
#include<vector>
#include<cmath>

#define MAX_SIZE 1024
using namespace std;

/* sum[i][j] denotes the sum of sum[i][0] ~ sum[i][j] */
int sum[MAX_SIZE][MAX_SIZE];

int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> sum[i][0];
		for (int j = 1; j < n; j++)
		{
			cin >> temp;
			sum[i][j] = temp + sum[i][j - 1];
		}
	}
	
	int a, b, c, d;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c >> d;
		b--; c--;
		/*update*/
		if (a == 0)
		{	
			int diff;
			if (c == 0)
				diff = d - sum[b][c];
			else
				diff = d - (sum[b][c] - sum[b][c - 1]);

			for (int j = c; j < n; j++)
				sum[b][j] += diff;
				
		}
		/*sum*/
		else
		{
			int e;
			cin >> e;

			d--;
			e--;

			int col_s = c;
			int col_e = e;
			int row_s = b;
			int row_e = d;
			int ans = 0;
			for (int j = row_s; j <= row_e; j++)
				if (col_s > 0)
					ans += (sum[j][col_e] - sum[j][col_s - 1]);
				else
					ans += sum[j][col_e];

			cout << ans << "\n";
		}

	}

	return 0;
}
/*
using fenwick tree 
https://www.acmicpc.net/blog/view/21
*/

#include<iostream>

using namespace std;

int tree[1025][1025];
int n, m;

int sum(int i, int j);
void update(int i, int j, int val);

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int val;
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> val;
			update(i, j, val);
		}

	int a;
	for (int i = 0; i < m; i++)
	{
		cin >> a;

		if (a == 0)
		{
			int r, c;
			cin >> r >> c >> val;

			int original = sum(r, c) - sum(r - 1, c) - sum(r, c - 1) + sum(r - 1, c - 1);

			update(r, c, val - original);

		}
		else 
		{
			int r1, c1, r2, c2;
			cin >> r1 >> c1 >> r2 >> c2;

			cout << sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) + sum(r1 - 1, c1 - 1) << "\n";
		}

	}

	return 0;
}


void update(int r, int c, int val)
{
	for (int i = r; i <= n; i += (i & -i))
		for (int j = c; j <= n; j += (j & -j))
			tree[i][j] += val;
}

int sum(int r, int c)
{
	int ans = 0;

	for (int i = r; i > 0; i -= (i & -i))
		for (int j = c; j > 0; j -= (j & -j))
			ans += tree[i][j];

	return ans;
}