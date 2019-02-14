/* https://www.acmicpc.net/problem/12796 */

#include<iostream>

using namespace std;

int main() 
{
	int k;
	cin >> k;
	cout << 3 << endl;
	cout << "1 1 1" << k + 1 << endl;

	return 0;
}

/*
1x1 1x1 1x(k+1)

min : 1*1*1 + 1*1*(k+1) = k + 2
max : 1*1(k+1) + 1*1(k+1) = 2k + 2


*/