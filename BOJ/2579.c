https://www.acmicpc.net/problem/2579
#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))

int main()
{
	int line;
	int i;
	scanf("%d", &line);
	int * stair_val = (int*)malloc(line * sizeof(int));
	
	for (i = 0; i < line; i++) 
	{
		scanf("%d", &stair_val[i]);
	}
	
	if(line == 1)
		printf("%d\n", stair_val[0]);
	else
	{
		int** Max = (int**)malloc(sizeof(int*) * 2);
		Max[0] = (int*)malloc(sizeof(int) * (line+1));
		Max[1] = (int*)malloc(sizeof(int) * (line+1));

		Max[0][0] = 0;
		Max[1][0] = 0;
		Max[0][1] = 0;
		Max[1][1] = stair_val[0];

		for (i = 2; i < line+1; i++)
		{
			Max[0][i] = stair_val[i-1] + Max[1][i - 1];
			Max[1][i] = stair_val[i-1] + max(Max[0][i - 2], Max[1][i - 2]);
		}

		printf("%d\n", max(Max[0][line], Max[1][line]));
		
		free(Max[0]);
		free(Max[1]);
		free(Max);
	}
	free(stair_val);
	return 0;
}

/*
	Note you can count from the starting point 0. From the point you can go to 1 or 2.
	0, 1, 2 is allowed sequence since 0 is not a stair. 
	
	The recurrence relation is easy to come up with if you make it with 2 params like OPT(i, k). 
	i denotes the number of movements and k whether you moved one or two that time.
	So, OPT(i,1) = stair_val(i) + OPT(i-1, 2)
		OPT(i,2) = stair_val(i) + max[OPT(i-2, 1) , OPT(i-2, 2)]
		OPT(i) = max[OPT(i,1), OPT(i,2)]
*/