#include<stdio.h>
/*https://www.acmicpc.net/problem/2908*/
int change(int a)
{
	int hun = a / 100;
	int ten = (a - hun * 100) / 10;
	int one = a % 10;

	return 100 * one + ten * 10 + hun;
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", change(a) < change(b) ? change(b) : change(a));

	return 0;
}