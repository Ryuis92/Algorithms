/* https://www.acmicpc.net/problem/2749 */

#include<iostream>

#define DIV 1000000
using namespace std;

int main() 
{
	long long n;
	cin >> n;
	
	int a, b, c;
	int period = 1;
	a = 0;
	b = 1;
	
	for (; period <= n; period++)
	{
		c = b;
		b = (a + b) % DIV;
		a = c;
		
		if (a == 0 && b == 1)
			break;
	}
	
	a = 0;
	b = 1;

	if (n % period == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 2; i <= n % period; i++)
	{
		c = b;
		b = (a + b) % DIV;
		a = c;
	}
	
	cout << b  << endl;

	return 0;
}

/*
Note that fib(n) % k has a period. And it depends on k. So if n is too big, then using period can 
make calculations easier and faster.

*/