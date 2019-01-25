/* https://www.acmicpc.net/problem/11066 */

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
int combine(int s, int e, vector<int>* list);
int total(int s, int e, vector<int>* list);
int opt[501][501];

int main()
{	
	int loop, chapter, temp;
	cin >> loop;

	while (loop--)
	{
		vector<int> list;
		cin >> chapter;

		memset(opt, 0, sizeof(opt));
		for (int i = 0; i < chapter; i++)
		{
			cin >> temp;
			list.push_back(temp);
		}
		cout << combine(1, chapter, &list) << endl;
	/*	for (int i = 2; i <= chapter; i++)
			cout << opt[1][i] << " ";
		cout << endl;*/
	}
	return 0;
}

int combine(int s, int e, vector<int>* list)
{
	if (opt[s][e])
		return opt[s][e];
	
	if (e - s == 1)
		return opt[s][e] = list->at(s - 1) + list->at(s);
	else if (s == e)
		return 0;

	opt[s][e] = INT_MAX;
	int index = s;
	int len = total(s, e, list);

	opt[s][e] = min(opt[s][e], combine(s + 1, e, list) + len);
	for (int i = s+1; i < e-1; i++)
	{	
		if (opt[s][e] > combine(s, i, list) + combine(i + 1, e, list) + len)
		{
			opt[s][e] = combine(s, i, list) + combine(i + 1, e, list) + len;
			index = i;
		}
	}
	if (opt[s][e] > combine(s, e - 1, list) + len)
	{
		opt[s][e] = combine(s, e - 1, list) + len;
		index = e-1;
	}
	//cout << s << ", " << index << ", " << e << "  " << opt[s][e] << endl;

	return opt[s][e];
}

int total(int s, int e, vector<int>* list) 
{
	int result = 0;
	for (int i = s - 1; i < e; i++)
		result += list->at(i);
	return result;
}

/*
-notation
F[i] : length of the i-th file. 
OPT(i, j) : the total cost of combining files from i to j.
Len(i, j) : the total length of combined files from i to j.

-recurrence relation.
OPT(i, j) = min(OPT(i, k) + OPT(k+1, j)) + Len(i,j) (i<= k <= j-1)

Let's say that there are two files A and B. Each has its length and cost. Note that they might be different. Combining them, we make a
new file C the length of which is the length of A + the length of B. Then what about the cost of making C? The costs of A and B + the length of C.
 




*/