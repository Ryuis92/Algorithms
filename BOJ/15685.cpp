/* https://www.acmicpc.net/problem/15685 */

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
#define MAX 101

struct point 
{
	int x, y;
};
typedef struct point point;

void makeDragon(int x, int y, int d, int level);
int count();
bool check[MAX][MAX];
bool map[MAX][MAX];
int n;

int main()
{
	cin >> n;

	int x, y, d, level;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> d >> level;

		makeDragon(x, y, d, level);
	}

	cout << count() << "\n";
	return 0;
}

// 0 : right 1: up, 2: left, 3:down
void makeDragon(int x, int y, int d, int level)
{
	/*initialize two base points*/
	vector<point> arr;
	arr.push_back({ x, y });

	if(d == 0)
		arr.push_back({ x+1, y });
	else if (d == 1)
		arr.push_back({ x, y-1});
	else if (d == 2)
		arr.push_back({ x-1, y });
	else
		arr.push_back({ x, y+1 });

	/*make dragon*/
	while(level--)
	{ 
		//all points will rotate around the last point in 90 degree clockwise
		point last = arr.back();
		int size = arr.size();

		/*x,y diff from last point*/
		int diff_x, diff_y;

		/*the first point will alway be the last rotated point*/
		for (int i = 1; i < size; i++)
		{
			point curr = arr[size - 1 - i];
			diff_x = last.x - curr.x;
			diff_y = last.y - curr.y;

			/*
			rotated coodinate
			If you observe the example carefully, you can find that the y diff is added to x of last, x diff is substracted from y of last
			*/
			arr.push_back({ (last.x + diff_y), (last.y - diff_x) });
		}
	}
	
	/*mark points in map*/
	for (point p : arr)
		map[p.y][p.x] = true;
}

int count()
{
	int ans = 0;
	for(int i = 0; i<MAX-1; i++)
		for (int j = 0; j < MAX - 1; j++)
		{
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
				ans++;
		}

	return ans;
}