/* https://www.acmicpc.net/problem/16234 */

#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

#define MAX 50
int n, L, R;
int map[MAX][MAX];
bool visit[MAX][MAX];
int ways[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int bfs(int row, int col);

struct coord
{
	int r, c;
};
typedef struct coord coord;

int main()
{
	cin >> n >> L >> R;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	int ans = 0;
	while (1)
	{
		int count = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (!visit[i][j])
					count += bfs(i, j);
		
		/*there's no union*/
		if (count == 0)
			break;
		ans++;
		memset(visit, false, sizeof(visit));
	}

	cout << ans << "\n";
	return 0;
}

int bfs(int row, int col)
{
	/*
	find union and total population to average it.
	*/
	int ans = 0;
	int i = 0;
	vector<coord> q;
	q.push_back({ row, col });
	visit[row][col] = true;
	
	/*To trace what coord bfs visited, use vector and index instead of queue*/
	while (i < q.size())
	{
		coord p = q[i++];
		ans += map[p.r][p.c];
		
		int next_row, next_col, diff;
		for (int i = 0; i < 4; i++)
		{
			next_row = p.r + ways[i][0];
			next_col = p.c + ways[i][1];

			if ((0 <= next_row && next_row < n) && (0 <= next_col && next_col < n) && !visit[next_row][next_col])
			{
				diff = abs(map[p.r][p.c] - map[next_row][next_col]);
				
				if (L <= diff && diff <= R)
				{
					visit[next_row][next_col] = true;
					q.push_back({ next_row, next_col });
				}
			}
		}
	}

	/*average population*/
	ans /= q.size();
	for (coord c : q)
		map[c.r][c.c] = ans;

	/*check if it made union with other nation*/
	return q.size() > 1;
}