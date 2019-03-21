/* https://www.acmicpc.net/problem/9576 */

#include<iostream>
#include<cstring>

using namespace std;

int adj[1000][2];
bool visit[1000];
int match[1000];
int n, m;

void bmatch();
int bfs(int s);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int test;
	cin >> test;

	while(test--)
	{
		memset(match, -1, sizeof(match));

		cin >> n >> m;

		int from, to;
		for (int i = 0; i < m; i++)
		{
			cin >> from >> to;
			adj[i][0] = from - 1;
			adj[i][1] = to - 1;
		}

		bmatch();
	}
	
	return 0;
}


void bmatch()
{
	int ans = 0;

	for (int i = 0; i < m; i++)
	{
		memset(visit, false, sizeof(visit));
		ans += bfs(i);
	}

	cout << ans << "\n";
}

int bfs(int s)
{
	if (visit[s])
		return 0;

	visit[s] = true;

	for(int i = adj[s][0]; i <= adj[s][1]; i++)
	{
		if (match[i] == -1 || (!visit[match[i]] && bfs(match[i])))
		{
			match[i] = s;
			return 1;
		}
	}

	return 0;
}