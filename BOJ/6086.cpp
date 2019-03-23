/* https://www.acmicpc.net/problem/6086 */

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>

#define MAX 52

using namespace std;
vector<int> adj[MAX];
int flow[MAX][MAX];
int capa[MAX][MAX];
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	
	/*
	input is given as alphabets and capacity
	tranform alpabets to 0~51.
	*/

	char from, to;
	int c;
	for (int i = 0; i < n; i++)
	{
		cin >> from >> to >> c;

		if ('A' <= from && from <= 'Z')
			from -= 'A';
		else
			from = from - 'a' + 26;

		if ('A' <= to && to <= 'Z')
			to -= 'A';
		else
			to = to - 'a' + 26;

		/*from and to can be repeatible*/
		capa[from][to] += c;
		capa[to][from] += c;
		
		//forward			
		adj[from].push_back(to);
		//backward
		adj[to].push_back(from);

	}

	int totalflow = 0;
	int sink = 'Z' - 'A';
	int source = 0;
	while (1)
	{
		/*using bfs find shortest s-t path until there's no such path*/
		int pre[MAX];
		memset(pre, -1, sizeof(pre));
		queue<int> q;
		q.push(source);

		while (!q.empty())
		{
			int curr = q.front(); q.pop();

			for (int next : adj[curr])
			{
				if (pre[next] != -1)
					continue;

				if (capa[curr][next] - flow[curr][next] > 0)
				{
					pre[next] = curr;
					q.push(next);

					/*find a s-t path*/
					if (next == sink)
						break;
				}
			}
		}

		/*cannot reach sink*/
		if (pre[sink] == -1)
			break;

		int f = 1000000;
		for (int i = sink; i > 0; i = pre[i])
			f = min(f, capa[pre[i]][i] - flow[pre[i]][i]);

		for (int i = sink; i > 0; i = pre[i])
		{
			//forward edge
			flow[pre[i]][i] += f;
			//backward edge
			flow[i][pre[i]] -= f;
		}

		totalflow += f;
	}

	cout << totalflow << "\n";
}
