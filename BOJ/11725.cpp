/* https://www.acmicpc.net/problem/11725 */

#include<cstdio>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	int n;
	stack<int> s;
	vector<vector<int>> arr;
	int parent, child;
	scanf("%d" , &n);

	int* ans = new int[n + 1];

	for (int i = 0; i < n + 1; i++)
	{
		ans[i] = -1;
		arr.push_back(vector<int>());
	}

	int a, b;
	for (int i = 0; i < n-1; i++)
	{
		scanf("%d %d", &a, &b);
		
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	s.push(1);
	while (!s.empty())
	{
		parent = s.top();
		s.pop();

		for (int j = 0; j < arr[parent].size(); j++)
		{
			child = arr[parent][j];
			
			if (child != ans[parent])
			{
				ans[child] = parent;
				s.push(child);
			}
		}
	}

	for (int i = 2; i <= n; i++)
		printf("%d\n", ans[i]);

	delete[] ans;

	return 0;
}