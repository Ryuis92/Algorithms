/* https://www.acmicpc.net/problem/2188 */

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

/*adjacent list to represent cow and cow house*/
vector<int> adj[200];

/* Represent if i-th cow (starting from zero) has been assigned to a house */
bool visit[200];
/* Denote the cow to which i-th house assigned */
int match[200];
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
		memset(visit, false, sizeof(visit));
		/* count the number of match */
		ans += bfs(i);
	}

	cout << ans << "\n";
}

int bfs(int s)
{	
	/*
	returns 1 if matching is possible.
	returns 0 if not.
	*/
	if (visit[s])
		return 0;

	visit[s] = true;

	for (int to : adj[s])
	{
		if (match[to] == -1 || bfs(match[to]))
		{	
			/*
			If to is already matched with a cow, then do bfs from the cow and see if the cow can find other house.
			*/
			match[to] = s;
			return 1;
		}
	}

	return 0;
}