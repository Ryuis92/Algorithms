/*
https://www.acmicpc.net/problem/2957
refer : https://vvshinevv.tistory.com/27
*/

#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
/* 
map is a container of pair <key, value>. As the word key indicates, key must be unique.
In map, elements are stored in a sorted order by key. 
map.upper_bound(x) returns the iterator, pointer, of the first element with the key greater than x.
map.lower_bound(x) returns the iterator, pointer, of the element with the key same with x.
*/


int main()
{
	int n, num, depth;
	map<int, long long> tree;
	map<int, long long>::iterator upper;
	map<int, long long>::iterator lower;
	long long sum = 0;

	/*set global upper and lower bound*/
	tree.insert({ 0,-1 });
	tree.insert({ 300001, -1 });

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		/*
		When you insert a new item in a binary search tree, it is inserted to the left of the smallest value that is greater than the value you are now inserting, or to right of the greatest value that is smaller than the added value.
		Between these two options, we choose the value in deeper level.
		*/

		scanf("%d", &num);
		upper = tree.upper_bound(num);
		lower = --tree.lower_bound(num);

		depth = max(upper->second, lower->second) + 1;

		tree.insert({ num, depth });
		sum += depth;
		printf("%lld\n", sum);
	}

	return 0;
}

