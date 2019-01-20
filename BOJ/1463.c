/*https://www.acmicpc.net/problem/1463*/

#include<stdio.h>
#include<stdlib.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))

int test_brute(int, int);

int main()
{
	int num;
	int* opt;
	int i;
	scanf("%d", &num);
	opt = (int*)malloc(sizeof(int) * (num + 1));
	opt[0] = 0;
	opt[1] = 0;

	for (i = 2; i < num+1; i++)
	{
		if (i % 3 == 0)
			opt[i] = min(opt[i / 3], opt[i - 1]) + 1;
		else if (i % 2 == 0)
			opt[i] = min(opt[i / 2], opt[i-1]) + 1;
		else
			opt[i] = opt[i - 1] + 1;
	}

	/*
	for(i = 300; i<num+1; i++)
		if(opt[i] != foo(0, i))
			printf("%d: %d %d\n", i,opt[i], foo(0, i));
	
	for (i = 1; i < num + 1; i++)
		printf("%d: %d\n", i, opt[i]);
	*/
	printf("%d\n", opt[num]);
	free(opt);
	return 0;
}

int test_brute(int count, int num) 
{
	if (num == 1)
		return count;

	int c1, c2, c3;

	if (num % 3 == 0)
		c1 = foo(count + 1, num / 3);
	else
		c1 = INT_MAX;
	
	if (num % 2 == 0)
		c2 = foo(count + 1, num / 2);
	else
		c2 = INT_MAX;

	c3 = foo(count + 1, num - 1);

	int min1 = min(c1, c2);
	int min2 = min(c2, c3);

	return min(min1,min2);
}

/*
Note
Even if N is a multiple of 3, don't take it granted that dividing it with 3 is best choice.
For example, 321 is a multiple of 3, but OPT[107] > OPT[320]. 
So you have compare OPT[N/2] or OPT[N/3] with OPT[N-1].

*/