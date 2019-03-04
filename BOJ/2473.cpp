/* https://www.acmicpc.net/problem/2473 */

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	vector<int>arr;
	int left, right;
	long long sum;
	int curr;
	long long total = 4000000000;
	int ans[] = { 0,0,0 };
	int input;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());
	
	for (int i = 0; i < n; i++)
	{
		/* 
		i < left < right this property always holds true.
		i remains fixed while left and right indices are changing.
		 */
		left = i+1;
		right = n - 1;

		while (left < right)
		{
			sum =  (long long)arr[i] + arr[left] + arr[right];

			if (abs(sum) < total)
			{
				total = abs(sum);
				ans[0] = arr[i]; 
				ans[1] = arr[left];
				ans[2] = arr[right];
			}
			/* 
			arr is ordered in ascending order. Our goal is to minimize total, or sum.
			if sum > 0, that means we need to choose smaller values. As arr is ordered array, decreasing index of right will do that.
			 */
			if (sum > 0)
				right--;
			else
				left++;
		}
	}
	
	
	/*Don't need to sort ans because i < left < right and arr[i] < arr[left] < arr[right] */
	printf("%d %d %d\n", ans[0], ans[1], ans[2]);

	return 0;
}