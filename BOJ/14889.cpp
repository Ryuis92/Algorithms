/* https://www.acmicpc.net/problem/14889 */
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>

#define MAX 21
using namespace std;
int dfs(int s, int count, int last);
int chem[MAX][MAX];
bool visit[MAX];
int n;
int half;

int main()
{
	cin >> n;
	half = n / 2;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> chem[i][j];

	cout << dfs(1, 1, 1) << "\n";
	return 0;
}

int dfs(int s, int count, int last)
{
	/*
	s: selected person by person 1.
	count : number of selected people
	last : the last one selected
	 */

	if (count == half)
	{	
		visit[s] = true;
		vector<int> x;
		vector<int> y;
		for (int i = 1; i <= n; i++)
		{
			if (visit[i])
				x.push_back(i);
			else
				y.push_back(i);
		}

		int total_x = 0;
		int total_y = 0;

		for (int i = 0; i < x.size(); i++)
			for (int j = i + 1; j < x.size(); j++)
			{
				total_x += chem[x[i]][x[j]];
				total_x += chem[x[j]][x[i]];

				total_y += chem[y[i]][y[j]];
				total_y += chem[y[j]][y[i]];
			}
/* debug
		cout << "X: ";
		for (int i = 0; i < x.size(); i++)
			cout << x[i] << " ";
		cout<< total_x << "\n";

		cout << "Y: ";
		for (int i = 0; i < x.size(); i++)
			cout << y[i] << " ";
		cout << total_y << "\n";
*/

		visit[s] = false;
		return abs(total_x - total_y);
	}

	visit[s] = true;
	int ans = 1e9;

	/*
	by using last, you can prevent duplicate computation
	For example 1, 2, 3 and 1, 3, 2 will give you the same results, but you have to compute both.
	So with last you can always move your idx forward, and this will prevent duplication.
	*/

	for (int i = last + 1; i <= n; i++)
		if (!visit[i])
			ans = min(ans, dfs(i, count + 1, i));

	visit[s] = false;

	return ans;
}