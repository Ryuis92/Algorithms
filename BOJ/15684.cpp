/* https://www.acmicpc.net/problem/15684 */

#include<iostream>
#include<vector>
#include<cmath>

#define ROW 30
#define COL 10
using namespace std;

bool down();

int n, m, h;
/* map[a][b] denotes b-th col's moving direction in a-th depth*/
int map[ROW][COL];
bool dfs(int s, int ladder, int limit);

int main()
{
	cin >> n >> m >> h;

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		a--;
		b--;
		// 1  ->
		// -1 <-
		map[a][b] = 1;
		map[a][b + 1] = -1;
	}

	for (int i = 0; i < 4; i++)
		if (dfs(0, 0, i))
		{
			cout << i << "\n";
			return 0;
		}
		
	cout << -1 << "\n";

	return 0;
}

bool down()
{
	/* check if the ending position is the same as the starting position for all column*/
	for (int i = 0; i < n; i++)
	{
		int curr = i;
		for (int j = 0; j < h; j++)
			curr += map[j][curr];

		if (curr != i)
			return false;
	}

	return true;
}

bool dfs(int s, int ladder, int limit)
{
	/*
	s: current depth
	ladder : the number of currently added ladders;
	limit : the maximum number of addible ladders
	*/

	if (ladder == limit)
	{
		return down();
	}

	for (int i = s; i < h; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			if (map[i][j] == 0 && map[i][j+1] == 0)
			{
				map[i][j] = 1;
				map[i][j + 1] = -1;

				if (dfs(i, ladder + 1, limit))
					return true;

				map[i][j] = 0;
				map[i][j + 1] = 0;
			}
		}
	}

	return false;
}