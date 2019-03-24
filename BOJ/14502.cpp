/* https://www.acmicpc.net/problem/14502 */

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct coord
{
	int row, col;
};

typedef struct coord coord;


vector<coord> virus;
vector<coord> zero;
int map[8][8];
int map_copy[8][8];
int n, m;
int ways[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // up, down, left, right

void bfs();
int count();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			
			//wall
			if (map[i][j] == 2)
				virus.push_back({ i,j });

			//blank
			if (map[i][j] == 0)
				zero.push_back({ i, j });
		}

	/*
	choose 3 blanks and set walls there.
	run bfs() and see how many are survived.
	*/
	int size = zero.size();
	for (int i = 0; i < size; i++)
	{
		//set wall
		map[zero[i].row][zero[i].col] = 1;
		for (int j = i + 1; j < size; j++)
		{
			//set wall
			map[zero[j].row][zero[j].col] = 1;
			for (int k = j + 1; k < size; k++)
			{
				//set wall
				map[zero[k].row][zero[k].col] = 1;
				
				//copy map to map_copy
				copy(&map[0][0], &map[0][0] + 64, &map_copy[0][0]);
				bfs();
				
				ans = max(ans, count());

				//remove wall
				map[zero[k].row][zero[k].col] = 0;
			}
			//remove wall
			map[zero[j].row][zero[j].col] = 0;
		}
		//remove wall
		map[zero[i].row][zero[i].col] = 0;
	}

	cout << ans << "\n";

	return 0;
}

void bfs()
{
	queue<coord> q;
	
	for (coord c : virus)
		q.push(c);

	while (!q.empty())
	{
		coord p = q.front(); q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int cur_r = p.row + ways[i][0];
			int cur_c = p.col + ways[i][1];

			if ( !((0 <= cur_r && cur_r < n) && (0 <= cur_c && cur_c < m)) )
				continue;

			if (map_copy[cur_r][cur_c] == 0)
			{
				map_copy[cur_r][cur_c] = 2;
				q.push({ cur_r, cur_c });
			}
		}
	}
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
