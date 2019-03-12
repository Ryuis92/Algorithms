/*https://www.acmicpc.net/problem/2098*/

#include<cstdio>
#include<algorithm>

#define CITY_MAX 16
#define MAX_LEN 65536 //= 2^16

const int max_val = 987654321;

int arr[CITY_MAX][CITY_MAX];
int memo[CITY_MAX][MAX_LEN];
int city_num;
int visit_all;
int TSP(int curr, int visit);
using namespace std;

int main()
{
	scanf("%d", &city_num);

	visit_all = (1 << city_num) - 1; //city_num 1's. 

	for (int i = 0; i < city_num; i++)
		for (int j = 0; j < city_num; j++)
			scanf("%d", (arr[i] + j));
	
	printf("%d\n", TSP(0, 1));

	return 0;
}

int TSP(int curr, int visit)
{
	if (visit == visit_all)
		/*there's no way to starting point*/
		if (arr[curr][0] == 0)
			return max_val;
		else
			/*go back to starting point*/
			return arr[curr][0];

	if (memo[curr][visit] != 0)
		return memo[curr][visit];

	int ans = max_val;
	for (int i = 1; i < city_num; i++)
		/*bitmask to find out where to visit*/
		if ((visit & (1 << i)) == 0 && (arr[curr][i] != 0))
			ans = min(ans, TSP(i, visit | (1 << i)) + arr[curr][i]);
	
	return memo[curr][visit] = ans;
}