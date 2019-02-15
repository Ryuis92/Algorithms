/* https://www.acmicpc.net/problem/1038 */
#include<iostream>

using namespace std;

int main() 
{
	int n;
	int count = 0;
	cin >> n;
	
	long long i = 0;
	long long temp;
	int before, after;
	int flag = true;
	int position;
	while (i <= 9876543210)
	{	
		temp = i;
		flag = true;
		position = 1;
		while (temp >= 10) 
		{
			before = temp % 10;
			temp /= 10;
			after = temp % 10;
			position *= 10;

			if (before >= after)
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			//cout << count << "-th: " << i << endl;
			if (count == n)
			{
				cout << i << endl;
				return 0;
			}
			count++;
			i++;
		}
		else 
		{
			i += position;
			i = i - (i % position);
		}
		
	}
	
	cout << -1 << endl;
	return 0;
}

/*
Explanation
First thing you must know is what is the range of possible decreasing numberes. To get this, find out the biggest number, which is 9876543210.
So, if you check each a number is decreasing or not, you have to look through 1 to 9876543210. The total number of checking will be over 9 billions.
This way will take a very long time. To minimize checking process, you need to skip some unpromising numbers. For example 4322, you can see the position of 10 is not increasing.
So you have to skip 4322~4329 and go to 4330. Now the position of 100 isn't increasing. Skip 4331~4399 and go to 4400. Again skip and go to 5000.
This way of skipping is to adding one to the number of first non-increasing position and making before the position all zeroes.
*/