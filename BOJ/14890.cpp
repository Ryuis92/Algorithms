/* https://www.acmicpc.net/problem/14890 */

#include<iostream>
#include<cstring>
#define MAX 100
using namespace std;

int n, len;
int map_row[MAX][MAX];
int map_col[MAX][MAX];
/*check for if ramp is put there*/
bool check[MAX];

int solve(int row, bool first);

int main()
{
	cin >> n >> len;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> map_row[i][j];
			map_col[j][i] = map_row[i][j];
		}

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		ans += solve(i, true);
		ans += solve(i, false);
	}

	cout << ans << "\n";
	return 0;
}

int solve(int row, bool first)
{
	/*
	first: if true see if row-th row is a possible way
		   if false see if row-th col is a possible way
	*/
	memset(check, false, sizeof(check));

	int(*map)[MAX];
	if (first)
		map = map_row;
	else
		map = map_col;

	for (int i = 0; i < n - 1; i++)
	{
		if (map[row][i] == map[row][i + 1])
			continue;

		else if (map[row][i] + 1 == map[row][i + 1])
		{
			if (i + 1 < len)
				return 0;

			int com = map[row][i];

			for (int j = i; j > i - len; j--)
			{
				if (com != map[row][j] || check[j])
					return 0;
				else
					check[j] = true;
			}
		}
		else if (map[row][i] - 1 == map[row][i + 1])
		{
			if ((n - 1) - (i + 1) + 1 < len)
				return 0;

			int com = map[row][i + 1];

			for (int j = i + 1; j < i + 1 + len; j++)
			{
				if (com != map[row][j] || check[j])
					return 0;
				else
					check[j] = true;
			}
		}
		else
			return 0;
	}
	//cout << first << ": " << row << "\n";
	return 1;
}