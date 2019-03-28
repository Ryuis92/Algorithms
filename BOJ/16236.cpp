/* https://www.acmicpc.net/problem/16236 */
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

#define MAX 20

struct shark
{
	int row, col, time;
};
typedef struct shark shark;

int map[MAX][MAX];
bool visit[MAX][MAX];
int n;
int row, col, big;
int ways[4][2] = { {-1,0} ,{0,-1}, {0, 1}, {1, 0} };
vector<shark> bfs();

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			/*find shark*/
			if (map[i][j] == 9)
			{
				row = i;
				col = j;
				map[i][j] = 0;
			}
		}

	int ans = 0;
	int eat_count = 0;
	big = 2;

	while (true)
	{
		/*Run bfs to find nearest fishes*/
		vector<shark> next = bfs();

		/*No fish available*/
		if (next.empty())
			break;

		/*find the proper fish: up > left */
		shark next_shark = next[0];
		for (int i = 1; i < next.size(); i++)
		{
			if (next_shark.row > next[i].row)
				next_shark = next[i];
			else if(next_shark.row == next[i].row && next_shark.col > next[i].col)
				next_shark = next[i];
		}

		/*move shark*/
		row = next_shark.row;
		col = next_shark.col;

		/*add moving time*/
		ans += next_shark.time;
		
		/*eat fish*/
		/*Do not set it 9 to denote that the shark is there*/
		map[row][col] = 0;
		eat_count++;

		if (eat_count == big)
		{
			big++;
			eat_count = 0;
		}

		memset(visit, false, sizeof(visit));
	}

	cout << ans << "\n";
}

vector<shark> bfs()
{
	queue<shark> q;
	vector<shark> food;
	q.push({ row, col, 0 });
	visit[row][col] = true;

	while (!q.empty())
	{
		shark p = q.front(); q.pop();

		/*Find nearest eatible fishes from the shark*/
		if (map[p.row][p.col] != 0 && map[p.row][p.col] < big)
		{
			food.push_back(p);

			while (!q.empty() && q.front().time == p.time)
			{
				shark p1 = q.front(); q.pop();
				if (map[p1.row][p1.col] != 0 && map[p1.row][p1.col] < big)
					food.push_back(p1);
			}

			return food;
		}

		for (int i = 0; i < 4; i++)
		{
			int next_row = p.row + ways[i][0];
			int next_col = p.col + ways[i][1];

			if ((0 <= next_row && next_row < n) && (0 <= next_col && next_col < n))
			{
				if (!visit[next_row][next_col] && map[next_row][next_col] <= big)
				{
					q.push({ next_row, next_col, p.time + 1 });
					visit[next_row][next_col] = true;
				}
			}
		}
	}

	return food;
}