/* https://www.acmicpc.net/problem/9577 */

#include<iostream>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;

/* visit denotes what file chunk i-th second is downloading. If not, -1 */
bool visit[101];
/*match represent when i-th chunk is downloaded */
int match[101];

/*n : the number of chunks, m: the number of peers */
int n, m;

int bfs(int s, set<int> adj[]);
void bmatch(set<int> adj[]);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int test;
	cin >> test;

	while(test--)
	{
		memset(match, -1, sizeof(match));

		/* available chunks at i-th second */
		set<int> adj[101];
		cin >> n >> m;

		int from, to, num;
		for (int i = 0; i < m; i++)
		{
			cin >> from >> to >> num;
			
			/*using set to avoid redundancy*/
			set<int> temp;
			int t;
			for (int j = 0; j < num; j++)
			{
				cin >> t;
				temp.insert(t);
			}

			set<int>::iterator iter;
			for (int j = from; j < to; j++)
				for(iter = temp.begin(); iter != temp.end(); iter++)
					{
						adj[j].insert((*iter));
					}
		}

		bmatch(adj);
	}
	
	return 0;
}


void bmatch(set<int> adj[])
{
	int count = 0;

	/*For each second find matching. If found all, return*/
	for (int i = 0; i < 100; i++)
	{
		if (adj[i].size() == 0)
			continue;

		memset(visit, false, sizeof(visit));
		count += bfs(i, adj);

		/* If found all return right away. This will minimize the total time. */
		if (count == n)
		{
			/*1 sec is needed to download*/
			cout << i + 1 << "\n";
			return;
		}
		
	}

	/* fail to download */
	cout << -1 << "\n";

}

int bfs(int s, set<int> adj[])
{
	if (visit[s])
		return 0;

	visit[s] = true;
	set<int>::iterator iter;
	for(iter = adj[s].begin(); iter != adj[s].end(); iter++)
	{
		int curr = *iter;
		
		if (match[curr] == -1 || (!visit[match[curr]] && bfs(match[curr], adj)))
		{
			match[curr] = s;
			return 1;
		}
	}

	return 0;
}