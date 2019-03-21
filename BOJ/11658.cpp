/* https://www.acmicpc.net/problem/11658 */

#include<iostream>
#include<vector>
#include<cmath>

#define MAX_SIZE 1024
using namespace std;

int arr[MAX_SIZE][MAX_SIZE];
int sum[MAX_SIZE][MAX_SIZE];

int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	
	for (int i = 0; i < n; i++)
	{	
		sum[i][0] = arr[i][0];
		for (int j = 1; j < n; j++)
			sum[i][j] = arr[i][j] + sum[i][j - 1];
	}
	int a, b, c, d;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c >> d;
		b--; c--;
		if (a == 0)
		{
			int diff = d - arr[b][c];
			arr[b][c] = d;

			for (int j = c; j < n; j++)
				sum[b][j] += diff;
				
		}
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