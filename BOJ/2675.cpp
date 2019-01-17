/* https://www.acmicpc.net/problem/2675 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int t;
	scanf("%d", &t);
	int i = 0;
	int iter;
	
	while (i++<t) 
	{
		char in[20];
		scanf("%d %s",  &iter, in);
		int size = iter * strlen(in) + 1;
		char* temp = (char*)malloc(sizeof(char) * size);
		for (int j = 0; j < strlen(in); j++)
			for (int k = 0; k < iter; k++)
			{
				temp[k + j * iter] = in[j];
			}

		temp[size - 1] = '\0';
		printf("%s\n", temp);
		free(temp);
	}
	return 0;
}