/* https://www.acmicpc.net/problem/2261 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstdio>

using namespace std;
int closestPair(int s, int e);
int cmpX(pair<int, int >&a, pair<int, int>&b);
int cmpY(pair<int, int >&a, pair<int, int>&b);

vector<pair<int, int>> listX;

int main()
{
	int n;
	cin >> n;
	
	int a, b, res;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		listX.push_back(make_pair(a, b));
	}
	sort(listX.begin(), listX.end(), cmpX);

	
	res = closestPair(0, n-1);
	cout << res << endl;
	return 0;
}

int cmpX(pair<int, int >&a, pair<int, int>&b) 
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int cmpY(pair<int, int >&a, pair<int, int>&b)
{
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int getDistance(pair<int, int >a, pair<int, int >b) 
{
	return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}

int closestPair(int s, int e)
{
	int ans = INT32_MAX;
	int size = e - s + 1;
	if (size <= 3)
	{
		for (int i = s; i <= e; i++)
			for (int j = i + 1; j <= e; j++)
				ans = min(ans, getDistance(listX[i], listX[j]));

		return ans;
	}
	
	int mid = (e+s)/ 2 ;
	int midx = listX[mid].first;
		
	ans = min(closestPair(s, mid), closestPair(mid+1, e));

	vector<pair<int, int>> center;
	for (int i = s; i <= e; i++)
		if((midx-listX[i].first)*(midx - listX[i].first) <= ans)
			center.push_back(listX[i]);

	sort(center.begin(), center.end(), cmpY);
	for (int i = 0; i < center.size(); i++)
		for (int j = i + 1; j < (i + 7) && j < center.size(); j++)
			ans = min(ans, getDistance(center[i], center[j]));

	return ans;
}