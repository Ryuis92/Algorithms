/* https://www.acmicpc.net/problem/1300 */

#include<cstdio>
#include<algorithm>

int main()
{
	int n, k;
	scanf("%d\n%d", &n, &k);

	long long left, right, mid, count, ans;
	left = 1;
	right = (long long)n * n;
	long long row_count;

	while (left <= right)
	{
		mid = (left + right) / 2;
		count = 0;

		/* calculate find how many numbers are smaller than mid */
		for (int i = 1; i <= n; i++)
		{
			/* 
			i-th row contains numbers of multiple of i: i*1, i*2, i*3 .... i*N
			So min(mid/i, N) is the number of values smaller than or equal to mid.
			To explain more detail. mid = i * m (1<=m <= mid).
			If we know what m is, we can position mid in i-th row. This means we can calculate how many values smaller than or eqaul to mid there are.
			*/
			row_count = mid / i;
			if (row_count > n)
				count += n;
			else
				count += row_count;
		}

		if (count < k)
			left = mid + 1;
		else
		{
			/*
			the reason why we consider the value of mid as a candidate when k > count is that it is possible mid is not in the arr.
			*/
			right = mid - 1;
			ans = mid;
		}
	}

	printf("%lld\n", ans);

	return 0;
}