/* https://www.acmicpc.net/problem/2618 */

#include<cstdio>
#include<utility>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

pair<int, int> accident[1001];
vector<int> accident_handle;
int memo[1001][1001];
int road_num, accident_num;
pair<int, int> car1_first;
pair<int, int> car2_first;

int getDistance(pair<int, int>* car, pair<int, int>* acc);

int dispatch(int pos1, int pos2)
{
	/*
	return minimum of distance when car1 is at pos1, car2 is at pos2
	pos1, pos2 points to the number of an accident. If a car handle an accident it must go to the location.
	*/
	if (pos1 == accident_num || pos2 == accident_num)
		return 0;

	if (memo[pos1][pos2] != 0)
		return memo[pos1][pos2];

	int next_acc = max(pos1, pos2) + 1;
	int car1_handle;
	int car2_handle;

	if (pos1 == 0)
		car1_handle = dispatch(next_acc, pos2) + getDistance(&car1_first, accident + next_acc);
	else
		car1_handle = dispatch(next_acc, pos2) + getDistance(accident + pos1, accident + next_acc);
	if(pos2 == 0)
		car2_handle = dispatch(pos1, next_acc) + getDistance(&car2_first, accident + next_acc);
	else
		car2_handle = dispatch(pos1, next_acc) + getDistance(accident + pos2, accident + next_acc);
	
	memo[pos1][pos2] = min(car1_handle, car2_handle);
	
	return memo[pos1][pos2];
}

void trace(int pos1, int pos2)
{
	if (pos1 == accident_num || pos2 == accident_num)
		return;

	int next_acc = max(pos1, pos2) + 1;
	int car1_handle;
	int car2_handle;

	if (pos1 == 0)
		car1_handle = memo[next_acc][pos2] + getDistance(&car1_first, accident + next_acc);
	else
		car1_handle = memo[next_acc][pos2] + getDistance(accident + pos1, accident + next_acc);

	if(pos2 == 0)
		car2_handle = memo[pos1][next_acc] + getDistance(&car2_first, accident + next_acc);
	else
		car2_handle = memo[pos1][next_acc] + getDistance(accident + pos2, accident + next_acc);

	if (car1_handle > car2_handle)
	{
		accident_handle.push_back(2);
		trace(pos1, next_acc);
	}
	else
	{
		accident_handle.push_back(1);
		trace(next_acc, pos2);
	}
}

int main()
{
	int ans;
	scanf("%d\n%d", &road_num, &accident_num);

	for (int i = 1; i <= accident_num; i++)
		scanf("%d %d", &accident[i].first, &accident[i].second);
	
	car1_first = { 1,1 };
	car2_first = { road_num, road_num };

	ans = dispatch(0, 0);
	printf("%d\n", ans);
	trace(0, 0);
	for (int i = 0; i < accident_num; i++)
		printf("%d\n", accident_handle[i]);

	return 0;
}

int getDistance(pair<int, int>* car, pair<int, int>* acc)
{
	return abs((*car).first - (*acc).first) + abs((*car).second - (*acc).second);
}