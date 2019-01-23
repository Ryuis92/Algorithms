/* https://www.acmicpc.net/problem/2156 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;
int search(int start, int end, int con, vector<int> val);

int main() 
{
	int num, temp;
	//cin >> num;
	srand((unsigned int)time(NULL));

	while (1) {
		vector<int> val;
		num = rand() % 10 + 1;
		cout << "num: " << num << endl;

		for (int i = 0; i < num; i++)
		{
			//cin >> temp;
			temp = rand() % 11;
			val.push_back(temp);
		}

		vector<int> optCon(num);
		vector<int> optNon(num);

		int Max = 0;
	
		for (int i = 0; i < num; i++)
		{
			int moneN = 0;
			int mtwoC = 0, mtwoN = 0;
			int mthrC = 0, mthrN = 0;

			if (i >= 1)
				moneN = optNon.at(i - 1);
			if (i >= 2) 
			{
				mtwoC = optCon.at(i - 2);
				mtwoN = optNon.at(i - 2);
			}
			if (i >= 3)
			{
				mthrC = optCon.at(i - 3);
				mthrN = optNon.at(i - 3);
			}

			optCon.at(i) = moneN + val.at(i);
			optNon.at(i) = max(max(mtwoC, mtwoN), max(mthrC, mthrN)) + val.at(i);

			int tempMax = max(optCon.at(i), optNon.at(i));
			Max = max(tempMax, Max);
		}
	}
	return 0;
}

int search(int start, int end, int con, vector<int> val) 
{
	if (start >= end)
		if (con > 1) return 0;
		else return val[start];
	
	int Max;
	if (con < 2)
	{
		Max = max(search(start + 1, end, con + 1, val) + val[start], search(start + 1, end, 0, val));
		return Max;
	}
	else
		return search(start + 1, end, 0, val);
}