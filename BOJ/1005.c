/* https://www.acmicpc.net/problem/1005 */ 

#include<stdio.h>
#include<string.h>

int edge[1001][1001];
int time[1001];
int opt[1001];
int nodeNum, edgeNum;
int target;

int DFS(int start);

int main()
{
	int line;
	scanf("%d", &line);

	while (line)
	{
		int i;
		int start, end;
		
		line--;
		scanf("%d %d", &nodeNum, &edgeNum);
		memset(edge, 0, sizeof(edge));
		memset(opt, -1, sizeof(opt));

		for (i = 1; i <= nodeNum; i++)
			scanf("%d ", &time[i]);
		for (i = 0; i < edgeNum; i++)
		{
			scanf("%d %d", &start, &end);
			edge[start][end] = 1;
		}
		scanf("%d", &target);
		printf("%d\n", DFS(target));
	}
	return 0;
}

int DFS(int start)
{
	int i;
	int cost;
	int max_val = 0;

	if (opt[start]!= -1)
		return opt[start];

	for (i = 1; i <= nodeNum; i++)
		if (edge[i][start])
		{
			cost = DFS(i);
			if (cost > max_val)
				max_val = cost;
		}
	opt[start] = max_val + time[start];

	return opt[start];
}


/* 
Note, time can be 0, so initializing opt to 0 will not help.
While in DFS, memoization helps cut out redundent calculations.
*/