/* https://www.acmicpc.net/problem/1316 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LENGTH 100
#define ALPHA_NUM 26

int main()
{
	char input[MAX_LENGTH];
	
	int loop;
	int count = 0;
	scanf("%d", &loop);

	for (int i = 0; i < loop; i++) 
	{	
		int fre[ALPHA_NUM] = { 0 };
		char now;
		int flag = true;
		scanf("%s", input);
		now = input[0];
		for (int j = 1; j < strlen(input); j++) 
		{
			if (now == input[j])
				continue;
			else 
			{	
				fre[now - 'a'] = -1;
				if (fre[input[j] - 'a'] < 0)
				{
					flag = false;
					break;
				}
				else
					now = input[j];
			}
		}
		if(flag)
			count++;
	}
	
	printf("%d\n", count);
	return 0;
}