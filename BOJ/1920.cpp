/* https://www.acmicpc.net/problem/1920 */

#include<cstdio>
#include<algorithm>

int arr[100000];

int main()
{
	int n, m;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", (arr + i));

	/* sort arr in ascending order for binary search */
	std::sort(arr, arr + n);
	
	scanf("%d", &m);
	int num;
	bool flag;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &num);
		int l = 0;
		int r = n;
		int mid;
		flag = false;
		
		/* binary seach */
		while (l <= r)
		{
			mid = (l + r) / 2;

			if (arr[mid] == num)
			{
				/* if find num in arr, set flag and leave the while loop */
				flag = true;
				break;
			}
			else if (arr[mid] < num)
				l = mid + 1;
			else
				r = mid-1;
		}

		printf("%d\n", flag);
	}

	return 0;
}