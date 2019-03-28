/* https://www.acmicpc.net/problem/15686 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAX 50

struct coord
{
	int row, col;
};
typedef struct coord coord;

int ways[4][2] = { {0,1},{0,-1},{1, 0},{-1, 0} };
int map[MAX][MAX];

bool check[13];
int dist[13][100];
int n, m;
vector<coord> v;
vector<coord> h;

int dfs(int s, int count);

int main()
{
	cin >> n >> m;
	// 0 : blank 1: house 2:chicken
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];

			/*chicken*/
			if (map[i][j] == 2)
				v.push_back({ i,j });
			/*house*/
			else if (map[i][j] == 1)
				h.push_back({ i, j });
		}

	/*compute dist btw house and chicken*/
	for(int i = 0; i < v.size(); i++)
		for (int j = 0; j < h.size(); j++)
		{
			dist[i][j] = abs(v[i].row - h[j].row) + abs(v[i].col - h[j].col);
		}

	cout << dfs(-1, 0) << "\n";

	return 0;
}

int dfs(int s, int count)
{
	/*
	s: s-th chicken, which is the last chicken selected
	count : number of chicken selected
	*/

	/*If all selected*/
	if (count == m)
	{
		int res = 0;

		/*For each house find nearest chicken*/
		for (int i = 0; i < h.size(); i++)
		{
			int sub = 1e9;
			for (int j = 0; j < 13; j++)
			{
				if (check[j])
					sub = min(sub, dist[j][i]);
			}
			res += sub;
		}
		return res;
	}

	int ans = 1e9;

	for (int i = s + 1; i < v.size(); i++)
	{
		check[i] = true;

		ans = min(ans, dfs(i, count + 1));

		check[i] = false;
	}
	return ans;
}