#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

#define MAX_SIZE 100000

struct point 
{
	int x, y;
	int diff_x, diff_y;
};

int convex_hull();
bool comp(point a, point b);
bool ccw(point a, point b, point c);

int n;
point p[MAX_SIZE];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> p[i].x >> p[i].y;
	}

	cout << convex_hull() << "\n";

	return 0;
}

int convex_hull()
{
	stack<point> s;

	/*initial diff are all 0s.*/
	sort(p, p + n, comp);
	
	/*pre-calculation for slope*/
	for (int i = 1; i < n; i++)
	{
		p[i].diff_x = p[0].x - p[i].x;
		p[i].diff_y = p[0].y - p[i].y;
	}

	sort(p + 1, p + n, comp);

	int i = 2;
	s.push(p[0]);
	s.push(p[1]);


	/*If ccw returns true then p[i] is on the left side of first-second vector.
	This makes sure that first-second vector is outter vector which constitues convex hull.
	If p[i] is one the right side of the vector, then that vector is not outter vector.
	*/
	while (i < n)
	{
		while (s.size() >= 2)
		{
			point second = s.top(); s.pop();
			point first = s.top();

			if (ccw(first, second, p[i]))
			{
				s.push(second);
				break;
			}
		}
		s.push(p[i++]);
	}

	return s.size();
}


bool comp(point a, point b)
{
	/* When sorting points according to the angle it makes with the base point p[0], don't need to calculate its angle. Use its slope instead */
	/* if slope is not the same */
	if (1LL * a.diff_y * b.diff_x != 1LL * a.diff_x * b.diff_y)
		return 1LL * a.diff_y * b.diff_x < 1LL * a.diff_x * b.diff_y;

	/* if slope is the same */
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

bool ccw(point a, point b, point c)
{
	/*To determine whether point c is on the left side of a-b vector*/
	long long s = 1LL * (b.x - a.x)*(c.y - a.y) - 1LL * (b.y - a.y)*(c.x - a.x);

	return s > 0;
}