/* https://www.acmicpc.net/problem/13460 */
#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;
#define WAYS 4

int n, m;
char board[10][11]; // contain \n, so 10 + 1
int r_row, r_col;
int b_row, b_col;
int four_way[][2] = { {-1,0}, {1,0}, {0, -1}, {0,1} };
bool visit[10][10][10][10];

struct pos {
	int r_row, r_col; //current position of red ball
	int b_row, b_col; //current position of blue ball
	int count;		  //counter of number of movement	
};
typedef struct pos pos;

int bfs();
void move(int& r, int& c, int dir);

int main()
{
	//read input
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", board[i]);

	//find red and blue
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'R')
			{
				r_row = i;
				r_col = j;
			}
			else if (board[i][j] == 'B')
			{
				b_row = i;
				b_col = j;
			}
		}

	int ans = bfs();
	printf("%d\n", ans);
		
	return 0;
}

int bfs()
{
	/* this is kind of finding the shortest path from red ball position to the hole position. So, it's a BFS problem.  */
	visit[r_row][r_col][b_row][b_col] = true;
	queue<pos> q;
	q.push({ r_row, r_col, b_row, b_col, 0 });

	int cr_row, cr_col, cb_row, cb_col; //current red, blue ball position

	while (!q.empty())
	{
		pos curr = q.front();
		q.pop();
		
		cr_row = curr.r_row;
		cr_col = curr.r_col;
		cb_row = curr.b_row;
		cb_col = curr.b_col;

		if (curr.count > 10)
			return -1;

		if (board[cr_row][cr_col] == 'O')
			return curr.count;
		
		for (int i = 0; i < WAYS; i++)
		{
			/* try up, down, left, right */
			int r_r = cr_row;
			int r_c = cr_col;
			int b_r = cb_row;
			int b_c = cb_col;

			move(r_r, r_c, i);
			move(b_r, b_c, i);

			if (board[b_r][b_c] == 'O')
				continue;
			/* when red and blue ball are in the same position */
			if (b_r == r_r && b_c == r_c)
			{
				switch (i)
				{
				case 0:
					cr_row > cb_row ? r_r++ : b_r++;
					break;
				case 1:
					cr_row > cb_row ? b_r-- : r_r--;
					break;
				case 2:
					cr_col > cb_col ? r_c++ : b_c++;
					break;
				case 3:
					cr_col > cb_col ? b_c-- : r_c--;
					break;
				}
			}

			if (!visit[r_r][r_c][b_r][b_c])
			{
				pos next = { r_r, r_c, b_r, b_c, curr.count + 1 };
				q.push(next);
				visit[r_r][r_c][b_r][b_c] = true;
			}
		}
	}
	return -1;
}

void move(int& r, int& c, int dir)
{
	while (1)
	{
		r += four_way[dir][0];
		c += four_way[dir][1];

		if (board[r][c] == '#')
		{
			r -= four_way[dir][0];
			c -= four_way[dir][1];
			break;
		}
		else if (board[r][c] == 'O')
			break;
	}
}

/* DFS version of implementation */
#include<cstdio>
#include<algorithm>
using namespace std;

int n, m;
char board[11][11];
int r_row, r_col;
int b_row, b_col;
int dfs(int r_row, int r_col, int b_row, int b_col, int way, int count);


int main()
{
	//read input
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", board[i]);

	//find red and blue
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'R')
			{
				r_row = i;
				r_col = j;
			}
			else if (board[i][j] == 'B')
			{
				b_row = i;
				b_col = j;
			}
		}
	int ans = dfs(r_row, r_col, b_row, b_col, -1, 0);

	if (ans > 10)
		printf("-1\n");
	else
		printf("%d\n", ans);
		
	return 0;
}

int dfs(int r_row, int r_col, int b_row, int b_col, int way, int count)
{
	if (count > 10)
		return count;

	int ans = 11;
	int four_way[][2] = { {-1,0}, {1,0}, {0, -1}, {0,1} };
	
	if (way != -1)
	{
		int r_plus = four_way[way][0];
		int c_plus = four_way[way][1];
		bool redfirst = false;
		bool redout = false;
		
		/* in case red ball and blue ball are lined together */
		if (way == 0)
		{
			if (r_col == b_col)
				if (r_row < b_row)
					redfirst = true;
				else
					redfirst = false;
		}
		else if (way == 1)
		{
			if (r_col == b_col)
				if (r_row > b_row)
					redfirst = true;
				else
					redfirst = false;
		}
		else if (way == 2)
		{
			if (r_row == b_row)
				if (r_col < b_col)
					redfirst = true;
				else
					redfirst = false;
		}
		else 
		{
			if (r_row == b_row)
				if (r_col > b_col)
					redfirst = true;
				else
					redfirst = false;
		}

		if (redfirst)
		{	
			/*if red ball go out through the hole. Blue ball also go out. so return the count if blue ball still inside the board*/
			while (board[r_row + r_plus][r_col + c_plus] != '#')
			{
				r_row += r_plus;
				r_col += c_plus;

				if (board[r_row][r_col] == 'O')
				{
					redout = true;
					r_row = -1;
					r_col = -1;
					break;
				}
			}

			while (board[b_row + r_plus][b_col + c_plus] != '#' && !(r_row == (b_row + r_plus) && r_col ==(b_col + c_plus)))
			{
				b_row += r_plus;
				b_col += c_plus;

				if (board[b_row][b_col] == 'O')
					return 11;
			}

			if (redout)
				return count;
		}
		else
		{
			while (board[b_row + r_plus][b_col + c_plus] != '#')
			{
				b_row += r_plus;
				b_col += c_plus;

				if (board[b_row][b_col] == 'O')
					return 11;
			}

			while (board[r_row + r_plus][r_col + c_plus] != '#' && !(b_row == (r_row + r_plus) && b_col ==(r_col + c_plus)))
			{
				r_row += r_plus;
				r_col += c_plus;

				if (board[r_row][r_col] == 'O')
					return count;
			}
		}
	}
	

	int row, col;
	for (int i = 0; i < sizeof(four_way) / sizeof(four_way[0]); i++)
	{
		row = four_way[i][0] + r_row;
		col = four_way[i][1] + r_col;
		if(board[row][col] != '#' || board[b_row + four_way[i][0]][b_col + four_way[i][1]] != '#')
			ans = min(ans, dfs(r_row, r_col, b_row, b_col, i, count + 1));
	}

	return ans;
}