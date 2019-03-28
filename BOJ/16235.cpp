/* https://www.acmicpc.net/problem/16235 */

#include<iostream>
#include<vector>
#include<deque>

#include<algorithm>
using namespace std;
#define MAX 10

int n, m, k;
/*In winter it is added*/
int add[MAX][MAX];
/*current nutirition status of the land*/
int food[MAX][MAX];
/*For N*N map keeping track of tree at each position*/
deque<int> tree[MAX][MAX];
int ways[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1,-1}, {1,0}, {1,1} };
int total;

/*summer work is done at the end of spring*/
void spring();
void fall();
void winter();

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> add[i][j];

	int row, col, age;
	for (int i = 0; i < m; i++)
	{
		cin >> row >> col >> age;
		tree[--row][--col].push_back(age);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			/*initialize food to 5*/
			food[i][j] = 5;

			/*
			sort each tree deque in ascending order by its age
			When a new tree is inserted into this deque, you have to push_front to keep the sorted state
			*/
			if (tree[i][j].empty())
				continue;
			sort(tree[i][j].begin(), tree[i][j].end());
		}

	/*initial number of trees*/
	total = m;
	while (k--)
	{
		spring();
		fall();
		winter();
	}

	cout << total << "\n";

	return 0;
}

void spring()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			/*tree is sorted in ascending order so you have to check until you meet a tree that cannot have food*/
			int k = 0;
			for (; k < tree[i][j].size(); k++)
			{
				if (food[i][j] >= tree[i][j][k])
				{
					food[i][j] -= tree[i][j][k];
					tree[i][j][k]++;
				}
				else
					break;
			}
			k = tree[i][j].size() - k;

			/* summer */
			while(k--)
			{
				food[i][j] += (tree[i][j].back() / 2);
				tree[i][j].pop_back();
				total--;
			}
		}
}

void fall()
{
	int next_row, next_col;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int age : tree[i][j])
			{
				if (age % 5 == 0)
					for (int k = 0; k < 8; k++)
					{
						next_row = i + ways[k][0];
						next_col = j + ways[k][1];

						if ((0 <= next_row && next_row < n) && (0 <= next_col && next_col < n))
						{
							tree[next_row][next_col].push_front(1);
							total++;
						}
					}
				
			}
}

void winter()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			food[i][j] += add[i][j];
}