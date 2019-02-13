/* https://www.acmicpc.net/problem/11778 */

#include<cstdio>
#include<algorithm>
using namespace std;

long long gcd(long long a, long long b);
void matrixMult(long long a[][2], long long b[][2]);
void power(long long a[][2], long long n);

long long mod = 1000000007LL;
long long base[2][2] = { {1, 1}, {1, 0} };

int main() 
{
	long long s, e;

	long long res[2][2] = { {1, 1}, {1, 0} };
	scanf("%lld %lld", &s, &e);

	long long gcd_input = gcd(max(s, e), min(s, e));

	power(res, gcd_input-1);
	
	printf("%lld\n", res[0][0] % mod);
	
	return 0;
}

long long gcd(long long a, long long b) 
{
	long long c;
	while (b) 
	{
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

void matrixMult(long long a[][2], long long b[][2]) 
{
	long long a00 = a[0][0] * b[0][0] + a[0][1] * b[1][0];
	long long a01 = a[0][0] * b[0][1] + a[0][1] * b[1][1];
	long long a10 = a[1][0] * b[0][0] + a[1][1] * b[1][0];
	long long a11 = a[1][0] * b[0][1] + a[1][1] * b[1][1];

	a[0][0] = a00 % mod;
	a[0][1] = a01 % mod;
	a[1][0] = a10 % mod;
	a[1][1] = a11 % mod;
}

void power(long long a[][2], long long n) 
{
	if (n <= 1)
		return;

	power(a, n / 2);
	matrixMult(a, a);
	if (n % 2 == 1)
		matrixMult(a, base);
}