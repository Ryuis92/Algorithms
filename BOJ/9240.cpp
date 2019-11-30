#include<cstdio>
#include<algorithm>
#include<stack>
#include<vector>
#include<cmath>
using namespace std;
#define MAX_SIZE 100000


struct point
{
	int x, y;
	int x_diff, y_diff;
};

bool comp(point a, point b);
void convex_hull();
bool ccw(point a, point b, point c);
int distance(point a, point b);

int n;	
point v[MAX_SIZE];


int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &v[i].x, &v[i].y);
	
	convex_hull();

	return 0;
}

bool comp(point a, point b)
{
	if (a.y_diff * b.x_diff != b.y_diff * a.x_diff)
		return a.y_diff * b.x_diff < b.y_diff * a.x_diff;
	
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

void convex_hull()
{
	/*construct convex hull*/
	sort(v, v + n, comp);

	for (int i = 1; i < n; i++)
	{
		v[i].x_diff = v[i].x - v[0].x;
		v[i].y_diff = v[i].y - v[0].y;
	}

	sort(v + 1, v + n, comp);

	stack<point> s;
	s.push(v[0]);
	s.push(v[1]);
	int i = 2;

	while (i < n)
	{
		while (s.size() > 1)
		{
			point second = s.top(); s.pop();
			point first = s.top();

			if (ccw(first, second, v[i]))
			{
				s.push(second);
				break;
			}
		}

		s.push(v[i++]);
	}

	/*find the two points that has the longest distance */

	vector<point> vec;

	while (!s.empty())
	{
		vec.push_back(s.top());
		s.pop();
	}

	int ans = 0;

	for (int j = 0; j < vec.size(); j++)
		for (int k = j + 1; k < vec.size(); k++)
			ans = max(ans, distance(vec[j], vec[k]));

	printf("%lf\n", sqrt(ans));
}

bool ccw(point a, point b, point c)
{
	int s = (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);

	return s > 0;
}

int distance(point a, point b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}