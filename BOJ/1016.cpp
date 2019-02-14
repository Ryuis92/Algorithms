/* https://www.acmicpc.net/problem/1016 */

#include<iostream>

using namespace std;
bool arr[10000001];

int main() 
{
	long long min_in, max_in;
	cin >> min_in >> max_in;
	int count = 0;
	for (long long i = 2; i*i <= max_in; i++)
	{
		long long start = min_in / (i*i);
		if (i*i*start != min_in)
			start++;

		while (start*i*i <= max_in)
		{
			arr[start*i*i - min_in] = true;
			start++;
		}
	}

	for (int i = 0; i < max_in - min_in + 1; i++)
	{
		if (arr[i] == false)
			count++;
	}
	cout << count << endl;
	return 0;
}