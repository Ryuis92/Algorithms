/* 
https://www.acmicpc.net/problem/2316 
ref : https://kks227.blog.me/220804885235?Redirect=Log&from=postView
*/

/*
Split a node into 2 nodes. one for receiver, the other for sender. Link them with capacity 1. This will allow only one flow go in and out of the node.
The reason why we don't use visit arr or something like bitmap is that if you use it, you cannot make backwarding the flow.

The maximum node size is 400 so we will numbering the i-th node's receiver and sender i and i+400.
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
vector<int> adj[800];
int flow[800][800];
int capa[800][800];
int n, p;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> p;
	
	/*
	preprocessing link receiver and sender.
	If you do it under the input reading part, it will give you redundancy. For example if input is (1,3) (1, 4) ... you will have two (1, 401).
	If you are going to use row-column representation of the graph, then you don't need to do this.
	*/
	for (int i = 2; i < 400; i++)
	{
		capa[i][i + 400] = 1;
		capa[i + 400][i] = 1;
		adj[i].push_back(i + 400);
		adj[400 + i].push_back(i);
	}

	int from, to;
	for (int i = 0; i < p; i++)
	{
		cin >> from >> to;

		from--;
		to--;
		
		capa[from + 400][to] = 1;
		capa[to + 400][from] = 1;

		//forward edges
		adj[from + 400].push_back(to);
		adj[to + 400].push_back(from);

		//backward edges
		adj[to].push_back(from + 400);
		adj[from].push_back(to + 400);
	}

	int totalflow = 0;

	while (1)
	{
		/* use bfs to find the shortest path from s to t*/

		//for tracing
		int pre[800];
		memset(pre, -1, sizeof(pre));
		pre[400] = 0;
		queue<int> q;
		
		// 0 - 400 has only capacity 1 so, // start from 400
		// or increase capa of 0 - 400 to some large number
		q.push(400);

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

					if (next == 1)
						break;
				}
			}
		}

		if (pre[1] == -1)
			break;

		for (int i = 1; i > 0; i = pre[i])
		{
			//forward edge
			flow[pre[i]][i] += 1;
			//backward edge
			flow[i][pre[i]] -= 1;
		}
		totalflow++;
	}

	cout << totalflow << "\n";
}
