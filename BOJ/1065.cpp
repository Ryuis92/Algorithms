/* https://www.acmicpc.net/problem/1065 */

#include<iostream>

using namespace std;

int main() 
{
	int n;
	cin >> n;

	int before, after;
	int temp;
	int d;
	bool flag;
	int count = 0;

	for (int i = 1; i <= n; i++)
	{
		temp = i;
		flag = true;
		before = temp % 10;
		after = (temp/10) % 10;
		d = before - after;

		while (temp >9)
		{
			before = temp % 10;
			temp /= 10;
			after = temp % 10;
			if (before - after != d)
			{
				flag = false;
				break;
			}
		}

		if (flag)
			count++;
		
	}
	
	cout << count << endl;

	return 0;
}