/* https://www.acmicpc.net/problem/14888 */

#include<iostream>
#include<cstring>
#include<algorithm>

#define MAX 11
#define DEFAULT 1000000001 // 1e9 + 1
using namespace std;
int dfs_max(int s, int plus, int minus, int multi, int div, int total);
int dfs_min(int s, int plus, int minus, int multi, int div, int total);

int n;
int arr[MAX];
int op[4]; // 0 :+, 1:-, 2 : x, 3: /

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < 4; i++)
		cin >> op[i];

	cout << dfs_max(0, op[0], op[1], op[2], op[3], arr[0]) << "\n"; 
	cout << dfs_min(0, op[0], op[1], op[2], op[3], arr[0]) << "\n";
	
	return 0;
}

int dfs_max(int s, int plus, int minus, int multi, int div, int total)
{
	if (s == n - 1)
		return total;

	int ans = -DEFAULT;

	if (plus != 0)
		ans = max(ans, dfs_max(s + 1, plus - 1, minus, multi, div, total + arr[s + 1]));
	if(minus != 0)
		ans = max(ans, dfs_max(s + 1, plus, minus - 1, multi, div, total - arr[s + 1])) ;
	if(multi != 0)
		ans = max(ans, dfs_max(s + 1, plus, minus, multi-1, div, total * arr[s + 1])) ;
	if(div != 0)
		ans = max(ans, dfs_max(s + 1, plus, minus, multi, div - 1, total / arr[s + 1]));

	return ans;
}

int dfs_min(int s, int plus, int minus, int multi, int div, int total)
{
	if (s == n - 1)
		return total;

	int ans = DEFAULT;

	if (plus != 0)
		ans = min(ans, dfs_min(s + 1, plus - 1, minus, multi, div, total + arr[s + 1]));
	if (minus != 0)
		ans = min(ans, dfs_min(s + 1, plus, minus - 1, multi, div, total - arr[s + 1]));
	if (multi != 0)
		ans = min(ans, dfs_min(s + 1, plus, minus, multi - 1, div, total * arr[s + 1]));
	if (div != 0)
		ans = min(ans, dfs_min(s + 1, plus, minus, multi, div - 1, total / arr[s + 1]));

	return ans;
}