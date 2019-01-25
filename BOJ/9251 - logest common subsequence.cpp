/* https://www.acmicpc.net/submit/9251 */
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int opt[1001][1001];

int main()
{	
	string X, Y;

	cin >> X;
	cin >> Y;

	for(int i = 1; i<= X.length(); i++)
		for (int j = 1; j <= Y.length(); j++) 
		{
			if (X[i - 1] == Y[j - 1])
				opt[i][j] = opt[i - 1][j - 1] + 1;
			else 
			{
				opt[i][j] = max(opt[i-1][j], opt[i][j-1]);
			}
		}
	cout << opt[X.length()][Y.length()] << endl;
	
	return 0;
}

/*
-Notation
X, Y each denotes the input strings.
OPT(i, j) means the length of the longest common subsequence of X[1] ~ x[i] and Y[1]~ Y[j] (indexes start from 1)

-recurrence relation
The idea is simple once you understand it. Assume we are comparing X, Y which are of the same length i. 
As the usual step of DP, undo last step. 
--first case
If X[i] == Y[i], we match them. then what is left is X[1]~X[i-1] and Y[1]~Y[i-1]. In this case OPT[i,i] = OPT[i-1, i-1] + 1
--second case
If X[i] != Y[i], we can't match them. So we are going to try to find a match for each X[i] and Y[i]. 
X[i] may have a match in Y[0] ~ Y[i-1]. likewise, Y[i] in X[0] ~ X[i-1]. we can check out these cases by comparing X[0]~X[i] and Y[0] ~ Y[i-1], and
X[0]~X[i-1] and Y[0] ~ Y[i]. We don't know which wii make a longer subsequence. Do compare the two.

This is the relation we found out by undoing the last step. We assumed the lengths of X, Y are equal, but they don't have to be. If they differs, that doesn't make any difference.
 




*/