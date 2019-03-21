/* https://www.acmicpc.net/problem/2407 */

#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int n, m;
string com[101][101];

string add(string a, string b);
string combination(int a, int b);

int main()
{
	scanf("%d %d", &n, &m);
	
	printf("%s\n", combination(n,m).c_str());
	return 0;
}

string add(string a, string b)
{
	string res;
	int sum = 0;

	/* sum means there's carry left */
	while (!a.empty() || !b.empty() || sum)
	{
		if (!a.empty())
		{
			sum += a.back() - '0';
			a.pop_back();
		}

		if (!b.empty())
		{
			sum += b.back() - '0';
			b.pop_back();
		}

		res += (sum % 10) + '0';

		/* if carry occurs this will be carried in the next iteration */
		sum /= 10;
	}

	/* we push from lower positions, so the position of 1 is at front. so reverse */
	reverse(res.begin(), res.end());
	return res;
}

string combination(int a, int b)
{
	/*use (a, b) = (a-1, b-1) + (a-1, b) */
	if (a == b || b == 0)
		return "1";

	string& res = com[a][b];
	if (com[a][b] != "")
		return res;

	 res = add(combination(a - 1, b), combination(a - 1, b - 1));

	 return res;
}