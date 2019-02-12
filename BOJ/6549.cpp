/* 
https://www.acmicpc.net/problem/6549

referrence
-https://www.acmicpc.net/blog/view/12
-https://sexycoder.tistory.com/107	

 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;


int main()
{
	while (true)
	{
		int num, temp;
		long long res;
		stack<int> s;
		vector<int> histogram;
		cin >> num;
		if (num == 0)
			break;
			
		for (int i = 0; i < num; i++)
		{
			cin >> temp;
			histogram.push_back(temp);
		}
		
		int curr;
		long long top;
		long long left, right;
		res = 0;
		for (int i = 0; i < num; i++)
		{
			curr = histogram[i];
			
			if (!s.empty())
			{
				top = histogram[s.top()];
				while (!s.empty() && histogram[s.top()] > curr)
				{
					top = histogram[s.top()];
					s.pop();
					right = i - 1;

					if (s.empty())
						left = 0;
					else
						left = s.top() + 1;
					res = max(res, top*(right-left+1));
				}
			}

			s.push(i);
		}
		right = num - 1;
		while (!s.empty()) 
		{
			top = histogram[s.top()];
			s.pop();

			if (s.empty())
				left = 0;
			else
				left = s.top() + 1;

			res = max(res, top*(right - left + 1));
		}
		
		cout << res << endl;
	}

	return 0;
}

