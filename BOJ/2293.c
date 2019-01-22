#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int solution(int* coin, int* result, int num, int target)
{
	int i, j;
	for (j = 0; j < num; j++)
		for (i = 1; i <= target; i++)	
			if (i - coin[j] >= 0)
				result[i] += result[i - coin[j]];

	return result[target];
}

int main()
{
	int num, target;
	int i;
	int* coin;
	int* result;
	scanf("%d %d", &num, &target);
	coin = (int*)malloc(sizeof(int) * num);
	result = (int*)malloc(sizeof(int) * (target + 1));
	memset(result, 0, sizeof(int) * (target + 1));
	result[0] = 1;
	for (i = 0; i < num; i++)
		scanf("%d", coin + i);

	printf("%d\n", solution(coin, result, num, target));

	free(coin);
	free(result);
	return 0;
}

/*
Just solve the example manually

   0  1  2  3  4  5  6  7  8  9  10
1  1  1  1  1  1  1  1  1  1  1  1

2  1  1  2  2  3  3  4  4  5  5  6

5  1  1  2  2  3  4  5  6  7  8  10


As you can see the first row, when coin value is 1, is first filled up, then second line, and finally last line done.

Note, you might have considered and failed.

	for (i = 1; i <= target; i++)	
		for (j = 0; j < num; j++)
			if (i - coin[j] >= 0)
				result[i] += result[i - coin[j]];

	
	To understand how it works, try result[3]. result[3] = result[2+1] ([1,1,1], [2,1]) + result[1+2]([1,2]) 
	The reason it fails to make right answer is that it contains redundant cases like [1,2], [2,1]. 
	The reason why this happens while in the right solution it doesn't, is that in the for loop you enumerate all coins for each i.
	And it makes orders. On the other hand, in the right solution one coin is considered after another is done. So, it also makes an order, but just one.
	
	

 */