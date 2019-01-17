/* https://www.acmicpc.net/problem/10809 */

#include<stdio.h>
#include<string.h>

int main()
{
	char in[100];
	int arr[26];
	scanf("%s", in);

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		arr[i] = -1;

	for (int i = 0; i < strlen(in); i++) 
	{
		char temp = in[i] - 'a';
		
		if (arr[temp] == -1)
			arr[temp] = i;
		else
			continue;
	}
	
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
		printf("%d ", arr[i]);

	return 0;
}