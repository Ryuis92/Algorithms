/* https://www.acmicpc.net/problem/14503 */

#include<iostream>
#define MAX 50
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int map[MAX][MAX];
	// 0 : up,  1 : right, 2 : down 3 : left
	int move[4][2] = { {-1, 0}, {0, 1}, {1,0}, {0, -1} };
	int n, m, d;
	int row, col;

	cin >> n >> m;
	cin >> row >> col >> d;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	
	int count = 0;
	while (1)
	{
		//cout << "(" << row << ", " << col << ")\n";
		/*When cleaning has not done yet*/
		if (map[row][col] == 0)
		{
			map[row][col] = -1;
			count++;
		}

		int turn_count = 0;
		bool flag = false;
		/* step 2 */
		while (1)
		{
			turn_count++;
			//turn left
			if (d == 0)
				d = 3;
			else
				d--;

			int next_r = row + move[d][0];
			int next_c = col + move[d][1];

			/*If there's available room*/
			if ((0<= next_r && next_r<n) && (0<=next_c && next_c < m) && map[next_r][next_c] == 0)
			{
				row = next_r;
				col = next_c;
				break;
			}

			/* surrounding 4 rooms are not available */
			if (turn_count == 4)
			{
				//up
				if (d == 0)
					row++;
				//right
				else if (d == 1)
					col--;
				//down
				else if (d == 2)
					row--;
				//left
				else
					col++;

				/*moving back is possible*/
				if ((0 <= row && row < n) && (0 <= col && col < m) && map[row][col] != 1)
					turn_count = 0;
				else
				{
					flag = true;
					break;
				}
			}
		}

		if (flag)
			break;
	}
	cout << count << "\n";
	return 0;
}