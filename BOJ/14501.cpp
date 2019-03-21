/* https://www.acmicpc.net/problem/14501 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

struct sched 
{
	int t, p;
};

typedef struct sched sched;

int work(int s);
int n;
vector<sched> arr;
/*memo denotes the max account of money you can make by working from day i-th.*/
int memo[15];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	int t, p;
	for (int i = 0; i < n; i++)
	{
		cin >> t >> p;

		arr.push_back({t, p});
	}

	int ans = 0;
	memset(memo, -1, sizeof(memo));
	for (int i = 0; i < n; i++)
		ans = max(ans, work(i));
	
	cout << ans << "\n";
	return 0;
}

int work(int s)
{
	sched curr = arr[s];
	int limit = s + curr.t;

	/*after quiting day*/
	if (limit > n)
		return 0;

	int& ans = memo[s];
	if (ans != -1)
		return ans;

	ans = 0;
	for (int i = s + 1; i < n; i++)
	{
		if (i >= limit)
			ans = max(ans ,work(i));
	}
	ans += curr.p;
	
	return ans;
}