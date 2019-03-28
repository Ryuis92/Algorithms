/* https://www.acmicpc.net/problem/15683 */

#include<iostream>
#include<cstring>
#include<vector>
#include<utility>
#include<algorithm>
#define MAX 8

using namespace std;

int map[MAX][MAX];
int map_copy[MAX][MAX];
int n, m;
vector<pair<int, int>> camera;
int dfs(int idx, vector<int> dir);
void check(int row, int col, int d);
int count();

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];

			if (1 <= map[i][j] && map[i][j] <= 5)
				camera.push_back({ i,j });
		}
	vector<int> dir;

	cout << dfs(0, dir) << "\n";

	return 0;
}

int dfs(int idx, vector<int> dir)
{
	if (idx == camera.size())
	{
		int row, col;
		int curr;
		int d;

		copy(&map[0][0], &map[0][0] + MAX * MAX, &map_copy[0][0]);

		for (int i = 0; i < idx; i++)
		{
			row = camera[i].first;
			col = camera[i].second;
			curr = map[row][col];
			d = dir[i];

			//1 camera
			//0: up, 1: right, 2 : down, 3: left
			if (curr == 1)
			{
				check(row, col, d);
			}
			// camera 2
			// 0: <- ->
			else if (curr == 2)
			{
				if (d == 0)
				{
					check(row, col, 1);
					check(row, col, 3);
				}
				else
				{
					check(row, col, 0);
					check(row, col, 2);
				}
			}
			//0 : l     1:   ㅡ    2 :  ㅡ         3:  ㅡㅣ
			//	   ㅡ       ㅣ            ㅣ            
			else if (curr == 3)
			{
				if (d == 0)
				{
					check(row, col, 0);
					check(row, col, 1);
				}
				else if (d == 1)
				{
					check(row, col, 1);
					check(row, col, 2);
				}
				else if (d == 2)
				{
					check(row, col, 2);
					check(row, col, 3);
				}
				else
				{
					check(row, col, 3);
					check(row, col, 0);
				}
			}
			else if (curr == 4)
			{
				if (d == 0)
				{
					check(row, col, 0);
					check(row, col, 1);
					check(row, col, 3);
				}
				else if (d == 1)
				{
					check(row, col, 0);
					check(row, col, 1);
					check(row, col, 2);
				}
				else if (d == 2)
				{
					check(row, col, 1);
					check(row, col, 2);
					check(row, col, 3);
				}
				else
				{
					check(row, col, 0);
					check(row, col, 2);
					check(row, col, 3);
				}
			}
			else
			{
				check(row, col, 0);
				check(row, col, 1);
				check(row, col, 2);
				check(row, col, 3);
			}
		}

		return count();
	}
	int ans = 1e9;


	if (map[camera[idx].first][camera[idx].second] == 5)
	{
		dir.push_back(0);
		ans = min(ans, dfs(idx + 1, dir));
		dir.pop_back();
	}
	else if (map[camera[idx].first][camera[idx].second] == 2)
	{
		dir.push_back(0);
		ans = min(ans, dfs(idx + 1, dir));
		dir.pop_back();

		dir.push_back(1);
		ans = min(ans, dfs(idx + 1, dir));
		dir.pop_back();
	}
	else
		for (int i = 0; i < 4; i++)
		{
			dir.push_back(i);
			ans = min(ans, dfs(idx + 1, dir));
			dir.pop_back();
		}

	return ans;
}

int count()
{
	int ans = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map_copy[i][j] == 0)
				ans++;
	
	return ans;
}

void check(int row, int col, int dir)
{
	//up
	if (dir == 0)
	{
		while (row >= 0 && map_copy[row][col] != 6)
		{
			if (map_copy[row][col] == 0)
				map_copy[row][col] = -1;
			row--;
		}
	}
	// right
	else if(dir == 1)
	{ 
		while (col < m && map_copy[row][col] != 6)
		{
			if (map_copy[row][col] == 0)
				map_copy[row][col] = -1;
			col++;
		}
	}
	// down
	else if (dir == 2)
	{
		while (row < n && map_copy[row][col] != 6)
		{
			if (map_copy[row][col] == 0)
				map_copy[row][col] = -1;
			row++;
		}
	}
	// left
	else
	{
		while (col >= 0 && map_copy[row][col] != 6)
		{
			if (map_copy[row][col] == 0)
				map_copy[row][col] = -1;
			col--;
		}
	}
}