/* https://www.acmicpc.net/problem/1157 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LENGTH 1000000
#define ALPHA_NUM 26

int main()
{
	char input[MAX_LENGTH];
	int fre[ALPHA_NUM] = { 0 };

	scanf("%s", input);

	for (int i = 0; i < strlen(input); i++) 
	{	
		int index;
		if ('a' <= input[i] && input[i] <= 'z')
		{
			fre[input[i] - 'a']++;
			index = input[i] - 'a';
		}
		else
		{
			fre[input[i] - 'A']++;
			index = input[i] - 'A';
		}
		if (fre[index] > strlen(input) / 2)
		{
			printf("%c", index + 'A');
			return 0;
		}
	}

	int max = 0;
	int same = -1;
	
	for (int i = 1; i < ALPHA_NUM; i++) 
	{
		if (fre[max] < fre[i]) 
		{
			max = i;
			same = -1;
		}
		else if (fre[max] == fre[i])
			same = i;
	}
	if (fre[max] == fre[same] && same > -1)
		printf("?\n");
	else
		printf("%c\n", 'A' + max);

	return 0;
}