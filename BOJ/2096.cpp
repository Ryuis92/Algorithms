/* https://www.acmicpc.net/problem/2096 */
#include<cstring>
#include<algorithm>
using namespace std;

int N;

int main()
{
	/*
	To find minimum and maximum total values, start from the top, or first input line.
	For this purpose, we have two sets of variables: pre_#_m, next_#_m.
	pre_#_m have the mininum and maxinum values accumulated from the first line. From pre, we can caculate next.
	*/
	int a, b, c;
	int pre_0_max, pre_1_max, pre_2_max;
	int pre_0_min, pre_1_min, pre_2_min;

	int next_0_max, next_1_max, next_2_max;
	int next_0_min, next_1_min, next_2_min;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &a, &b, &c);

		if (i == 0)
		{
			pre_0_max = a;
			pre_0_min = a;

			pre_1_max = b;
			pre_1_min = b;

			pre_2_max = c;
			pre_2_min = c;
		}
		else
		{
			next_0_min = a + min(pre_0_min, pre_1_min);
			next_0_max = a + max(pre_0_max, pre_1_max);

			next_2_min = c + min(pre_1_min, pre_2_min);
			next_2_max = c + max(pre_1_max, pre_2_max);

			next_1_min = b + min(min(pre_0_min, pre_1_min), min(pre_1_min, pre_2_min));
			next_1_max = b + max(max(pre_0_max, pre_1_max), max(pre_1_max, pre_2_max));

			pre_0_max = next_0_max;
			pre_0_min = next_0_min;

			pre_1_max = next_1_max;
			pre_1_min = next_1_min;

			pre_2_max = next_2_max;
			pre_2_min = next_2_min;
		}
	}

	int big, small;
	big = max(max(pre_0_max, pre_1_max), max(pre_1_max, pre_2_max));
	small = min(min(pre_0_min, pre_1_min), min(pre_1_min, pre_2_min));
	
	printf("%d %d\n", big, small);
	
	return 0;
}
