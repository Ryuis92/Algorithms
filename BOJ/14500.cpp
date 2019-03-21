/* https://www.acmicpc.net/problem/14500 */

#include<iostream>
#include<algorithm>

#define MAX_LEN 500
using namespace std;

int n, m;
int map[MAX_LEN][MAX_LEN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	
	int row = n - 1;
	int col = 0;

	int ans = 0;
	//square
	for(int j = 0; j < n - 1; j++)
		for (int i = 0; i < m - 1; i++)
		{
			int temp = 0;

			temp += map[row - j][col + i];
			temp += map[row - j][col + 1 + i];
			temp += map[row - 1 - j][col + i];
			temp += map[row - 1 - j][col + 1 + i];

			ans = max(ans, temp);
		}
	
	// l
	for(int j = 0 ; j < n - 3; j++)
		for (int i = 0; i < m; i++)
		{
			int temp = 0;

			temp += map[row - j][col + i];
			temp += map[row - 1 - j][col + i];
			temp += map[row - 2 - j][col + i];
			temp += map[row - 3 - j][col + i];

			ans = max(ans, temp);
		}
	
	// ㅡ
	for (int j = 0; j < n; j++)
		for (int i = 0; i < m - 3; i++)
		{
			int temp = 0;

			temp += map[row - j][col + i];
			temp += map[row - j][col + i + 1];
			temp += map[row - j][col + i + 2];
			temp += map[row - j][col + i + 3];


			ans = max(ans, temp);
		}
	

	// ㅗ
	for (int j = 0; j < n - 1; j++)
		for (int i = 0; i < m - 2; i++)
		{
			int temp = 0;

			temp += map[row - j][col + i];
			temp += map[row - j][col + i + 1];
			temp += map[row - j][col + i + 2];
			temp += map[row -1 - j][col + i + 1];


			ans = max(ans, temp);
		}

	// ㅜ
	for (int j = 0; j < n - 1; j++)
		for (int i = 0; i < m - 2; i++)
		{
			int temp = 0;

			temp += map[row - 1 - j][col + i];
			temp += map[row - 1 - j][col + i + 1];
			temp += map[row - 1 - j][col + i + 2];
			temp += map[row - j][col + i + 1];


			ans = max(ans, temp);
		}

	// ㅏ
	for (int j = 0; j < n - 2; j++)
		for (int i = 0; i < m - 1; i++)
		{
			int temp = 0;

			temp += map[row - j][col + i];
			temp += map[row - 1 - j][col + i];
			temp += map[row - 2 - j][col + i];
			temp += map[row - 1 - j][col + 1 + i];

			ans = max(ans, temp);
		}

	// ㅓ
	for (int j = 0; j < n - 2; j++)
		for (int i = 0; i < m - 1; i++)
		{
			int temp = 0;

			temp += map[row - j][col + 1 +i];
			temp += map[row - 1 - j][col + 1 + i];
			temp += map[row - 2 - j][col + 1 + i];
			temp += map[row - 1 - j][col+ i];

			ans = max(ans, temp);
		}
	
	// * *     *
	//   *     *
	//   *   * *
	for (int j = 0; j < n - 2; j++)
		for (int i = 0; i < m - 1; i++)
		{
			int temp = 0;

			temp += map[row - j][col + 1 + i];
			temp += map[row - 1 - j][col + 1 + i];
			temp += map[row - 2 - j][col + 1 + i];
			temp += map[row - 2 - j][col + i];

			ans = max(ans, temp);

			temp -= map[row - 2 - j][col + i];
			temp += map[row - j][col + i];

			ans = max(ans, temp);
		}
	
	// * *   *
	// *     *
	// *     * *
	for (int j = 0; j < n - 2; j++)
		for (int i = 0; i < m - 1; i++)
		{
			int temp = 0;

			temp += map[row - j][col + i];
			temp += map[row - 1 - j][col + i];
			temp += map[row - 2 - j][col + i];
			temp += map[row - 2 - j][col + 1 + i];

			ans = max(ans, temp);


			temp -= map[row - 2 - j][col + 1 + i];
			temp += map[row - j][col + i + 1];
			ans = max(ans, temp);
		}
	
	//
	// *            *
	// * * *    * * *
	for (int j = 0; j < n - 1; j++)
		for (int i = 0; i < m - 2; i++)
		{
			int temp = 0;

			temp += map[row - j][col + i];
			temp += map[row - j][col + i + 1];
			temp += map[row - j][col + i + 2];
			temp += map[row - 1 - j][col + i];

			ans = max(ans, temp);

			temp -= map[row - 1 - j][col + i];
			temp += map[row - 1 - j][col + i + 2];

			ans = max(ans, temp);
		}

	// 
	// * * *  * * *  
	//     *  *
	for (int j = 0; j < n - 1; j++)
		for (int i = 0; i < m - 2; i++)
		{
			int temp = 0;

			temp += map[row - 1 - j][col + i];
			temp += map[row - 1 - j][col + i + 1];
			temp += map[row - 1 - j][col + i + 2];
			temp += map[row - j][col + i + 2];

			ans = max(ans, temp);

			temp -= map[row - j][col + i + 2];
			temp += map[row - j][col + i];

			ans = max(ans, temp);

		}

	// *      *
	// * *  * *
	//   *  *
	for (int j = 0; j < n - 2; j++)
		for (int i = 0; i < m - 1; i++)
		{
			int temp = 0;
			temp += map[row - 1 -j][col + i];
			temp += map[row - 1 -j][col + i + 1];

			temp += map[row - 2 - j][col + i];
			temp += map[row - j][col + i + 1];
			ans = max(ans, temp);

			temp -= map[row - 2 - j][col + i];
			temp -= map[row - j][col + i + 1];

			temp += map[row - 2 - j][col + i + 1];
			temp += map[row - j][col + i];

			ans = max(ans, temp);
		}

	//   * *   * *
	// * *       * *
	//
	for (int j = 0; j < n - 1; j++)
		for (int i = 0; i < m - 2; i++)
		{
			int temp = 0;
			temp += map[row - j][col + i + 1];
			temp += map[row - 1 - j][col + i + 1];

			temp += map[row - j][col + i];
			temp += map[row - 1 - j][col + i + 2];
			ans = max(ans, temp);

			temp -= map[row - j][col + i];
			temp -= map[row - 1 - j][col + i + 2];

			temp += map[row - j][col + i + 2];
			temp += map[row - 1 - j][col + i];

			ans = max(ans, temp);
		}

	cout << ans << "\n";

	return 0;
}