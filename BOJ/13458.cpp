/* https://www.acmicpc.net/problem/13458 */
#include<cstdio>
#include<cmath>

#define MAX_LEN 1000000

using namespace std;

int app[MAX_LEN];
int n, b, c;

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", (app + i));
	scanf("%d %d", &b, &c);

	long long count = 0;

	for (int i = 0; i < n; i++)
	{
		if (app[i] <= b)
			count += 1;
		else
			count += ceil((app[i] - b) / (double)c) + 1;
	}

	printf("%lld\n", count);
	return 0;
}