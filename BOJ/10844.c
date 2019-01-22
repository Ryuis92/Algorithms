/* https://www.acmicpc.net/problem/10844 */

#include<stdio.h>

#define DIV 1000000000

void nextStep(int fre[])
{
	int temp[10];

	for (int i = 0; i < 10; i++)
		temp[i] = fre[i];

	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
			fre[i] = temp[1];
		else if (i == 9)
			fre[i] = temp[8];
		else
			fre[i] = (temp[i - 1] + temp[i + 1]) % DIV;
	}
}

int main()
{
	int n, i;
	int total = 0;
	int fre[10] = { 0,1,1,1,1,1,1,1,1,1 };
	scanf("%d", &n);

	for (i = 1; i < n; i++)
		nextStep(fre);

	for (i = 0; i < 10; i++)
		total += fre[i];
	printf("%d\n", total % DIV);
	return 0;
}