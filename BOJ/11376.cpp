/* https://www.acmicpc.net/problem/11376 */

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<int> adj[1000];
bool visit[1000];
int match[1000];
int n, m;

void bmatch();
int bfs(int s);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(match, -1, sizeof(match));

	cin >> n >> m;

	int num, to;
	for (int i = 0; i < n; i++)
	{
		cin >> num;

		for (int j = 0; j < num; j++)
		{
			cin >> to;
			adj[i].push_back(to - 1);
		}
	}

	bmatch();
	return 0;
}


void bmatch()
{
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		/*. Everyone can handle at most 2 works. Run bipartite matching twice for each one. */
		memset(visit, false, sizeof(visit));
		ans += bfs(i);

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

	for (int to : adj[s])
	{
		if (match[to] == -1 || (!visit[match[to]] && bfs(match[to])))
		{
			match[to] = s;
			return 1;
		}
	}

	return 0;
}