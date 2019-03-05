/* https://www.acmicpc.net/problem/1654 */

#include<cstdio>
#include<algorithm>

/*Input are values 1~ 2^31-1, so int is enough*/
int arr[10000];

int main()
{
	int k, n;
	scanf("%d %d", &k, &n);

	for (int i = 0; i < k; i++)
		scanf("%d", arr + i);

	std::sort(arr, arr + k);
	
	/*left + right will exceed the range of int, which will results in overflow*/
	long long ans = 0;
	long long left, right;
	long long mid;
	long long count;

	/* 
	Set right to the largest value of k.
	Normally, the answer will be in range 1~ the smallest value of k.
	But, In some cases where it is too small, we must ignore it.
	*/
	left = 1;
	right = arr[k-1];
	
	while(left <= right)
	{
		count = 0;
		mid = (left + right) / 2;
		for (int num : arr)
			count += (num / mid);
		
		if (count >= n)
		{	
			/*In case when count > n, we still consider the mid of it as a candidate*/
			ans < mid ? ans = mid : ans;
			left = mid + 1;
		}
		else
			right = mid-1;
	}
	
	printf("%lld\n", ans);
	return 0;
}