/* https://www.acmicpc.net/problem/2470 */

#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	vector<int> plus;
	vector<int> minus;

	int input;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);

		if (input > 0)
			plus.push_back(input);
		else
			minus.push_back(input);
	}


	sort(minus.begin(), minus.end());
	sort(plus.begin(), plus.end());

	if (plus.size() == 0)
	{
		/*When only positive values are given*/
		printf("%d %d\n", minus[minus.size() - 2], minus[minus.size() - 1]);
		return 0;
	}
	else if (minus.size() == 0)
	{
		/*When only negative values are given*/
		printf("%d %d\n", plus[0], plus[1]);
		return 0;
	}

	int total = 2000000001;
	int a, b;
	int curr;

	for (int i = 0; i < plus.size(); i++)
	{
		int l = 0;
		int r = minus.size();
		int mid;

		while (l < r)
		{
			/*do binary search to find proper position of plus[i] in minus*/
			mid = (l + r) / 2;
			
			if (abs(minus[mid]) < plus[i])
				r = mid;
			else
				l = mid + 1; 
		}

		for (int j = -1; j < 2; j++)
		{	/*compare back and forth */
			if (0 <= r + j && r + j < minus.size())
			{
				curr = abs(plus[i] + minus[r + j]);
				if (curr < total)
				{
					total = curr;
					a = minus[r + j];
					b = plus[i];
				}
			}
		}
	}

	/*In case plus+plus or minus + minus are minimum*/
	if (plus.size() > 1)
	{
		if (total > plus[0] + plus[1])
		{
			total = plus[0] + plus[1];
			a = plus[0];
			b = plus[1];
		}
	}

	if (minus.size() > 1)
	{
		if (total > abs(minus[minus.size() - 2] + minus[minus.size() - 1]))
		{
			total = abs(minus[minus.size() - 2] + minus[minus.size() - 1]);
			a = minus[minus.size() - 2];
			b = minus[minus.size() - 1];
		}
	}
	printf("%d %d\n", a, b);

	return 0;
}

/* Using the property of absolute value */
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n;

bool comp(int a, int b)
{
	return abs(a) < abs(b);
}

int main()
{
	scanf("%d", &n);
	vector<int>arr;
	int a, b, total;
	total = 2000000001;

	int input;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input);
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end(), comp);

	/*
	You sort the arr by its abs value.
	To find the smallest sum of two values, you must pick two similar values, but with different signs like -1, 1.
	By sorting this way, similar values with different signs will be adjacents to each other.
	*/

	for(int i = 0; i<n-1; i++)
		if (total > abs(arr[i] + arr[i + 1]))
		{
			total = abs(arr[i] + arr[i + 1]);
			a = arr[i];
			b = arr[i + 1];
		}

	
	a < b ? printf("%d %d\n", a, b) : printf("%d %d\n", b, a);

	return 0;
}