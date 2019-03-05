/* https://www.acmicpc.net/problem/10815 */

#include<cstdio>
#include<algorithm>

int arr[500000];

int main()
{
	int n, m;
	scanf("%d" , &n);

	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	std::sort(arr, arr + n);
	
	scanf("%d", &m);
	int target;
	int left, right, mid;
	bool flag;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &target);
		
		left = 0;
		right = n;
		flag = false;

		while (left <= right)
		{
			mid = (left + right) / 2;
			if (arr[mid] == target)
			{
				flag = true;
				break;
			}
			else if (arr[mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}

		printf("%d ", flag);
	}
	printf("\n");
	return 0;
}