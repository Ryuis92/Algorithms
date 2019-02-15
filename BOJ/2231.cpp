/* https://www.acmicpc.net/submit/2231 */

#include<iostream>

using namespace std;

int main() 
{
	int n;
	cin >> n;
	
	int sum;
	int temp;
	for (int i = 1; i < n; i++)
	{
		sum = i;
		temp = i;
		while (temp)
		{
			sum += temp % 10;
			temp /= 10;
		}

		if (sum == n)
		{
			cout << i << endl;
			return 0;
		}
	}

	cout << 0 << endl;

	return 0;
}