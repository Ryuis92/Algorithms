/* https://www.acmicpc.net/problem/11689 */ 
/*refference https://librewiki.net/wiki/%EC%98%A4%EC%9D%BC%EB%9F%AC_%ED%94%BC_%ED%95%A8%EC%88%98*/

#include<iostream>

using namespace std;

int main() 
{
	long long n;
	double res;
	cin >> n;
	
	res = n;

	for (long long i = 2; i*i <= n; i++)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
			{
				n /= i;
			}
			res *= (1 - 1.0 / (double)i);
		}
	}
	if(n > 1)
		res *= (1 - 1.0 / (double)n);

	cout << (long long)res << endl;
	return 0;
}