/* https://www.acmicpc.net/problem/5639 */

#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int arr[10000];
void getPost(int s, int e);

int main()
{
	int temp;
	int count = 0;

	while (scanf("%d", &temp)!= EOF)
		arr[count++] = temp;
	
	getPost(0, count - 1);
	
	return 0;
}

void getPost(int s, int e)
{
	if (s > e)
		return;

	int root = arr[s];
	int i = s + 1;
	while (arr[i] < root && i <= e) i++;
	i--;

	getPost(s + 1, i);
	getPost(i + 1, e);
	printf("%d\n", root);
}