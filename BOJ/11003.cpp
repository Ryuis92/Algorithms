/* https://www.acmicpc.net/problem/11003 */

#include<cstdio>
#include<algorithm>
#include<deque>
#include<utility>
using namespace std;

int main()
{
	int N, L;
	scanf("%d %d", &N, &L);
	
	deque<pair<int,int>> dq;
	/*dq works as a sliding window*/
	int a;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a);

		/* 
		To keep the dq in the ordered state, we pop from back if the last element is larger than new input
		What we need is the smallest value of the sliding window, so if the new input is smaller than the last element, we don't need it.
		*/
		while (!dq.empty() && dq.back().first > a)
			dq.pop_back();

		dq.push_back(make_pair(a, i));

		/*delete elements from front which are out of sliding window range*/
		while (!dq.empty() && dq.front().second <= i - L)
			dq.pop_front();
		/*print the mininum of the sliding window*/
		printf("%d ", dq.front().first);
	}
	printf("\n");
	
	return 0;
}