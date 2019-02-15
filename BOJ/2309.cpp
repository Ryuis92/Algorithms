/* https://www.acmicpc.net/problem/2309 */ 

#include<iostream>
#include<algorithm>
using namespace std;

int main() 
{
	int h[9];
	int sum = 0;
	bool flag = false;
	for (int i = 0; i < 9; i++)
	{
		cin >> h[i];
		sum += h[i];
	}
	sum -= 100;
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (h[i] + h[j] == sum)
			{
				h[i] = 0;
				h[j] = 0;
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}

	sort(h, h + 9);
	for (int k = 2; k < 9; k++)
	{
		cout << h[k] << endl;
	}
	return 0;
}