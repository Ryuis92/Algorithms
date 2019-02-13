/* https://www.acmicpc.net/problem/1015 */
#include<vector>
#include<cstdio>
#include<utility>
#include<algorithm>

using namespace std;

int compare(pair<int, int> &a, pair<int, int> &b);


int main()
{
	int n;
	vector<pair<int, int>> list;
	scanf("%d", &n);
	int* ans = new int[n];

	int temp;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		list.push_back(make_pair(temp, i));
	}
	sort(list.begin(), list.end(), compare);

	for (int i = 0; i < n; i++)
	{
		ans[list[i].second] = i;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	delete[] ans;
	return 0;
}

int compare(pair<int, int> &a, pair<int, int> &b) 
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
