/* https://www.acmicpc.net/problem/14499 */

#include<cstdio>

using namespace std;

int map[20][20];
int dir;
int height, width, dice_r, dice_c, comm_num;
int dice[6]; // 0: down, 5: up, 1: front, 3: back, 2:left, 4:right

int main() 
{
	scanf("%d %d %d %d %d", &height, &width, &dice_r, &dice_c, &comm_num);

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			scanf("%d", (map[i] + j));

	for (int i = 0; i < comm_num; i++)
	{
		scanf("%d", &dir);
		
		//right
		if (dir == 1)
		{
			if (width <= dice_c + 1)
				continue;
			
			dice_c++;
			int temp[] = {dice[4],dice[1], dice[0] , dice[3], dice[5], dice[2]};

			for (int j = 0; j < 6; j++)
				dice[j] = temp[j];
		}
		//left
		else if (dir == 2)
		{
			if (0 > dice_c - 1)
				continue;

			dice_c--;

			int temp[] = {dice[2], dice[1], dice[5], dice[3], dice[0], dice[4]};
			for (int j = 0; j < 6; j++)
				dice[j] = temp[j];

		}
		//up
		else if (dir == 3)
		{
			if (0 > dice_r - 1)
				continue;

			dice_r--;

			int temp[] = { dice[1],dice[5],dice[2],dice[0],dice[4],dice[3] };
			for (int j = 0; j < 6; j++)
				dice[j] = temp[j];
		}
		//down
		else
		{
			if (height <= dice_r + 1)
				continue;

			dice_r++;

			int temp[] = { dice[3],dice[0],dice[2],dice[5],dice[4],dice[1] };
			for (int j = 0; j < 6; j++)
				dice[j] = temp[j];
		}

		//after rolling the dice, check the bottom of dice and the map.
		if (map[dice_r][dice_c] == 0)
			map[dice_r][dice_c] = dice[0];
		else
		{
			dice[0] = map[dice_r][dice_c];
			map[dice_r][dice_c] = 0;
		}

		printf("%d\n", dice[5]);
	}

	return 0;
}