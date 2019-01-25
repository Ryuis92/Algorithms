/**/
#include<iostream>
#include<vector>
using namespace std;

int DFS(int col, int row);
vector<vector<int>> map;
vector<vector<int>> visit;

int main() 
{
	int col, row;
	cin >> col;
	cin >> row;

	for (int i = 0; i < col; i++)
	{
		vector<int> temp;
		vector<int> tempBit;
		int in;
		for (int j = 0; j < row; j++)
		{
			cin >> in;
			temp.push_back(in);
			tempBit.push_back(-1);
		}
		map.push_back(temp);
		visit.push_back(tempBit);
	}

	cout << DFS(0, 0);
	return 0;
}

int DFS(int col, int row) 
{
	if (visit[col][row] != -1)
		return visit[col][row];

	if (col == map.size() - 1 && row == map[0].size() - 1)
		return visit[col][row] = 1;

	int curr = map[col][row];
	visit[col][row] = 0;
	if (col > 0 && map[col - 1][row] < curr)
		visit[col][row] += DFS(col - 1, row);
	if(col + 1 < map.size() && map[col + 1][row] < curr)
		visit[col][row] += DFS(col + 1, row);
	if(row > 0 && map[col][row - 1] < curr)
		visit[col][row] += DFS(col, row -1);
	if(row + 1 < map[col].size() && map[col][row + 1] < curr)
		visit[col][row] += DFS(col, row + 1);

	return visit[col][row];
}

/*
The reason why initialize visit to -1. Assume that you did it to 0.
Now consider the path 50 - 20 - 10. 10 is surrounded by greater numbers so, it returns 0.
This 0 means that we searched paths from 10 but there's no proper paths. However, 0 also means not searched yet.
So, the path 50 - 20 - 15 - 14 - 13 - 11 - 10 doesn't take advantage of visit and do redundant calculations again.
That's why you have initialize visit not to 0 but to some other negative value.

50	30	30
20	10	60
15	11	9
14	13	7

*/