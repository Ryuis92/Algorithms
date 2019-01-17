#include<stdio.h>
#define MAX_LENGTH 1000001

/*https://www.acmicpc.net/problem/1152*/

int main()
{
	char c[MAX_LENGTH];
	int count = 1;

	fgets(c, MAX_LENGTH, stdin);

	if (c[0] == '\n' || (c[0] == ' ' && c[1] == '\n'))
	{
		printf("0\n");
		return 0;
	}
		
	for (int i = 1; i < strlen(c) - 2; i++)
	{
		if (c[i] == ' ')
			count++;
	}

	printf("%d\n", count);
	return 0;