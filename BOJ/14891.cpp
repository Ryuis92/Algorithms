/* https://www.acmicpc.net/problem/14891 */

#include<iostream>
#include<cstring>
#include<string>
#define MAX 100
using namespace std;

//2: left, 6: right
string arr[4];
bool check[4];

string rotate_cc(int i, int clock);
void rotate(int i, int clock);

int main()
{
	for (int i = 0; i < 4; i++)
		cin >> arr[i];
	
	int n;
	cin >> n;
	int num, clock;
	for (int i = 0; i < n; i++)
	{
		cin >> num >> clock;
		num--;
		
		memset(check, false, sizeof(check));
		rotate(num, clock);
	}
	int ans = 0;
	int plus = 1;
	for (int i = 0; i < 4; i++)
	{
		if (arr[i].front() == '1')
			ans += plus;
		
		plus *= 2;
	}
	
	cout << ans << "\n";
	return 0;
}

string rotate_cc(int i, int clock)
{
	//1: clockwise 
	if(clock == 1)
		return arr[i].back() + arr[i].substr(0, 7);
	//-1: counter-clockwise
	else
		return arr[i].substr(1, 7) + arr[i].front();
}

void rotate(int i, int clock)
{
	check[i] = true;

	string pre = arr[i];
	arr[i] = rotate_cc(i, clock);

	if (i - 1 >= 0 && !check[i-1] && arr[i - 1][2] != pre[6])
		rotate(i - 1, -clock);

	if (i + 1 < 4 && !check[i+1] && arr[i + 1][6] != pre[2])
		rotate(i + 1, -clock);
}
