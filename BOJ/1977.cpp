/* https://www.acmicpc.net/problem/1977 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int s, e;
	cin >> s >> e;
	int sum = 0;
	int min_val = e;
	for (int i = s; i <= e; i++)
	{
		if ((int)sqrt(i) * (int)sqrt(i) == i)
		{
			sum += i;
			min_val = min(min_val, i);
		}
	}

	if (sum == 0)
		cout << -1 << endl;
	else
		cout << sum << endl << min_val << endl;

	return 0;
}
