/*https://www.acmicpc.net/problem/5373*/

#include<iostream>
#include<string>
using namespace std;

// 0: up, 1: down, 2:left, 3:right, 4:front, 5:back
// 0: white, 1:yellow, 2: green, 3:blue, 4:red, 5:orange
/*
		 u0 u1 u2
		 u3 u4 u5
		 u6 u7 u8

l0 l1 l2 f0 f1 f2 r0 r1 r2 b0 b1 b2
l3 l4 l5 f3 f4 f5 r3 r4 r5 b3 b4 b5
l6 l7 l8 f6 f7 f8 r6 r7 r8 b6 b7 b8

		 d0 d1 d2
		 d3 d4 d5
		 d6 d7 d8
*/
int cube[6][9] = { {0,0,0,0,0,0,0,0,0},
				   {1,1,1,1,1,1,1,1,1},
				   {2,2,2,2,2,2,2,2,2},
				   {3,3,3,3,3,3,3,3,3},
				   {4,4,4,4,4,4,4,4,4},
			       {5,5,5,5,5,5,5,5,5}
};

char color[6] = {'w', 'y', 'g', 'b', 'r', 'o'};
int cube_copy[6][9];
int back_up[6][9];

void rotate(string r);
void rotate(int i, bool clock);

int main()
{
	int test;
	cin >> test;

	copy(&cube[0][0], &cube[0][0] + 6 * 9, &back_up[0][0]);
	while (test--)
	{
		int n;
		cin >> n;
		copy(&back_up[0][0], &back_up[0][0] + 6 * 9, &cube[0][0]);
		for (int i = 0; i < n; i++)
		{
			string r;
			cin >> r;

			rotate(r);

			/*
			for (int p = 0; p < 6; p++)
			{
				cout << p << "\n";
				for (int k = 0; k < 3; k++)
				{
					for (int j = 0; j < 3; j++)
						cout << color[cube[p][3 * k + j]];
					cout << "\n";
				}
				cout << "\n";
			}
			*/
		}
		
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << color[cube[0][3 * i + j]];
			cout << "\n";
		}		
	}

	return 0;
}

// 0: up, 1: down, 2:left, 3:right, 4:front, 5:back

void rotate(string r)
{
	copy(&cube[0][0], &cube[0][0] + 6 * 9, &cube_copy[0][0]);
	bool clock = (r[1] == '+');
	if (r[0] == 'L')
	{
		rotate(2, clock);
		//0,4,1 5
		if (clock)
		{
			cube[4][0] = cube_copy[0][0];
			cube[4][3] = cube_copy[0][3];
			cube[4][6] = cube_copy[0][6];

			cube[1][0] = cube_copy[4][0];
			cube[1][3] = cube_copy[4][3];
			cube[1][6] = cube_copy[4][6];

			cube[5][2] = cube_copy[1][6];
			cube[5][5] = cube_copy[1][3];
			cube[5][8] = cube_copy[1][0];

			cube[0][0] = cube_copy[5][8];
			cube[0][3] = cube_copy[5][5];
			cube[0][6] = cube_copy[5][2];
		}
		// 0, 5, 1, 4
		else
		{
			cube[5][2] = cube_copy[0][6];
			cube[5][5] = cube_copy[0][3];
			cube[5][8] = cube_copy[0][0];

			cube[1][6] = cube_copy[5][2];
			cube[1][3] = cube_copy[5][5];
			cube[1][0] = cube_copy[5][8];

			cube[4][0] = cube_copy[1][0];
			cube[4][3] = cube_copy[1][3];
			cube[4][6] = cube_copy[1][6];

			cube[0][0] = cube_copy[4][0];
			cube[0][3] = cube_copy[4][3];
			cube[0][6] = cube_copy[4][6];
		}
	}
	else if (r[0] == 'R')
	{
		rotate(3, clock);
		// 0, 5, 1, 4
		if (clock)
		{
			cube[5][6] = cube_copy[0][2];
			cube[5][3] = cube_copy[0][5];
			cube[5][0] = cube_copy[0][8];

			cube[1][8] = cube_copy[5][0];
			cube[1][5] = cube_copy[5][3];
			cube[1][2] = cube_copy[5][6];

			cube[4][2] = cube_copy[1][2];
			cube[4][5] = cube_copy[1][5];
			cube[4][8] = cube_copy[1][8];

			cube[0][2] = cube_copy[4][2];
			cube[0][5] = cube_copy[4][5];
			cube[0][8] = cube_copy[4][8];
		}
		// 0, 4, 1, 5
		else
		{
			cube[4][2] = cube_copy[0][2];
			cube[4][5] = cube_copy[0][5];
			cube[4][8] = cube_copy[0][8];

			cube[1][2] = cube_copy[4][2];
			cube[1][5] = cube_copy[4][5];
			cube[1][8] = cube_copy[4][8];

			cube[5][6] = cube_copy[1][2];
			cube[5][3] = cube_copy[1][5];
			cube[5][0] = cube_copy[1][8];

			cube[0][8] = cube_copy[5][0];
			cube[0][5] = cube_copy[5][3];
			cube[0][2] = cube_copy[5][6];
		}
	}
	else if (r[0] == 'U')
	{
		rotate(0, clock);
		//2, 5, 3, 4  .. 0 1 2
		if (clock)
		{
			cube[5][0] = cube_copy[2][0];
			cube[5][1] = cube_copy[2][1];
			cube[5][2] = cube_copy[2][2];

			cube[3][0] = cube_copy[5][0];
			cube[3][1] = cube_copy[5][1];
			cube[3][2] = cube_copy[5][2];

			cube[4][0] = cube_copy[3][0];
			cube[4][1] = cube_copy[3][1];
			cube[4][2] = cube_copy[3][2];

			cube[2][0] = cube_copy[4][0];
			cube[2][1] = cube_copy[4][1];
			cube[2][2] = cube_copy[4][2];
		}
		// 2 4 3 5
		else
		{
			cube[4][0] = cube_copy[2][0];
			cube[4][1] = cube_copy[2][1];
			cube[4][2] = cube_copy[2][2];

			cube[3][0] = cube_copy[4][0];
			cube[3][1] = cube_copy[4][1];
			cube[3][2] = cube_copy[4][2];

			cube[5][0] = cube_copy[3][0];
			cube[5][1] = cube_copy[3][1];
			cube[5][2] = cube_copy[3][2];

			cube[2][0] = cube_copy[5][0];
			cube[2][1] = cube_copy[5][1];
			cube[2][2] = cube_copy[5][2];
		}
	}
	else if (r[0] == 'D')
	{
		rotate(1, clock);
		//2, 4, 3, 5
		if (clock)
		{
			cube[4][6] = cube_copy[2][6];
			cube[4][7] = cube_copy[2][7];
			cube[4][8] = cube_copy[2][8];

			cube[3][6] = cube_copy[4][6];
			cube[3][7] = cube_copy[4][7];
			cube[3][8] = cube_copy[4][8];

			cube[5][6] = cube_copy[3][6];
			cube[5][7] = cube_copy[3][7];
			cube[5][8] = cube_copy[3][8];

			cube[2][6] = cube_copy[5][6];
			cube[2][7] = cube_copy[5][7];
			cube[2][8] = cube_copy[5][8];
		}
		//2, 5, 3, 4
		else
		{
			cube[5][6] = cube_copy[2][6];
			cube[5][7] = cube_copy[2][7];
			cube[5][8] = cube_copy[2][8];

			cube[3][6] = cube_copy[5][6];
			cube[3][7] = cube_copy[5][7];
			cube[3][8] = cube_copy[5][8];

			cube[4][6] = cube_copy[3][6];
			cube[4][7] = cube_copy[3][7];
			cube[4][8] = cube_copy[3][8];

			cube[2][6] = cube_copy[4][6];
			cube[2][7] = cube_copy[4][7];
			cube[2][8] = cube_copy[4][8];
		}
	}
	else if (r[0] == 'F')
	{
		rotate(4, clock);
		//0, 3, 1, 2
		if (clock)
		{
			cube[3][0] = cube_copy[0][6];
			cube[3][3] = cube_copy[0][7];
			cube[3][6] = cube_copy[0][8];

			cube[1][0] = cube_copy[3][6];
			cube[1][1] = cube_copy[3][3];
			cube[1][2] = cube_copy[3][0];

			cube[2][2] = cube_copy[1][0];
			cube[2][5] = cube_copy[1][1];
			cube[2][8] = cube_copy[1][2];

			cube[0][6] = cube_copy[2][8];
			cube[0][7] = cube_copy[2][5];
			cube[0][8] = cube_copy[2][2];
		}
		//0, 2, 1, 3
		else
		{
			cube[2][2] = cube_copy[0][8];
			cube[2][5] = cube_copy[0][7];
			cube[2][8] = cube_copy[0][6];

			cube[1][0] = cube_copy[2][2];
			cube[1][1] = cube_copy[2][5];
			cube[1][2] = cube_copy[2][8];

			cube[3][0] = cube_copy[1][2];
			cube[3][3] = cube_copy[1][1];
			cube[3][6] = cube_copy[1][0];

			cube[0][6] = cube_copy[3][0];
			cube[0][7] = cube_copy[3][3];
			cube[0][8] = cube_copy[3][6];
		}
	}
	// B
	else if(r[0] == 'B')
	{
		rotate(5, clock);
		//0 2 1 3
		if (clock)
		{
			cube[2][0] = cube_copy[0][2];
			cube[2][3] = cube_copy[0][1];
			cube[2][6] = cube_copy[0][0];

			cube[1][6] = cube_copy[2][0];
			cube[1][7] = cube_copy[2][3];
			cube[1][8] = cube_copy[2][6];

			cube[3][2] = cube_copy[1][8];
			cube[3][5] = cube_copy[1][7];
			cube[3][8] = cube_copy[1][6];

			cube[0][0] = cube_copy[3][2];
			cube[0][1] = cube_copy[3][5];
			cube[0][2] = cube_copy[3][8];
		}
		//0 3 1 2

		else
		{
			cube[3][2] = cube_copy[0][0];
			cube[3][5] = cube_copy[0][1];
			cube[3][8] = cube_copy[0][2];

			cube[1][6] = cube_copy[3][8];
			cube[1][7] = cube_copy[3][5];
			cube[1][8] = cube_copy[3][2];

			cube[2][0] = cube_copy[1][6];
			cube[2][3] = cube_copy[1][7];
			cube[2][6] = cube_copy[1][8];

			cube[0][0] = cube_copy[2][6];
			cube[0][1] = cube_copy[2][3];
			cube[0][2] = cube_copy[2][0];
		}
	}
}

void rotate(int i, bool clock)
{
	int temp[9] = { 0 };
	copy(&cube[i][0], &cube[i][0] + 9, &temp[0]);
	if (clock)
	{
		// 0, 2, 8, 6 -> 2, 8, 6, 0 
		// 1, 5, 7, 3 -> 5, 7, 3, 1
		cube[i][2] = temp[0];
		cube[i][8] = temp[2];
		cube[i][6] = temp[8];
		cube[i][0] = temp[6];

		cube[i][5] = temp[1];
		cube[i][7] = temp[5];
		cube[i][3] = temp[7];
		cube[i][1] = temp[3];
	}
	else
	{
		// 0, 6, 8, 2 -> 6, 8, 2, 0
		// 1, 3, 7, 5 -> 3, 7, 5, 1
		cube[i][6] = temp[0];
		cube[i][8] = temp[6];
		cube[i][2] = temp[8];
		cube[i][0] = temp[2];

		cube[i][3] = temp[1];
		cube[i][7] = temp[3];
		cube[i][5] = temp[7];
		cube[i][1] = temp[5];
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*simpler version*/
#include<iostream>

using namespace std;
/*

          53 52 51
		  50 49 48
		  47 46 45
			
	      00 01 02
 	      03 04 05
		  06 07 08

18 19 20  27 28 29  36 37 38  45 46 47
21 22 23  30 31 32  39 40 41  48 49 50
24 25 26  33 34 35  42 43 44  51 52 53

		  09 10 11
		  12 13 14
		  15 16 17


	      02 01 00 
	  38  45 46 47  18
	  41            21
	  44            24
		  17 16 15	
*/
/*index cube*/
int cube[6][3][3];
/*for each index assign a color*/
char mapping[54];

/*
indices for rotation.
When a side rotates, 4 sides rotate togetger
*/
int side[6][12] = { {18,19,20,27,28,29,36,37,38,45,46,47},
					{53,52,51,44,43,42,35,34,33,26,25,24},
					{15,12, 9,33,30,27, 6 ,3, 0,47,50,53},
					{9 ,10,11,42,39,36, 8, 7, 6,20,23,26},
					{51,48,45, 2, 5, 8,29,32,35,11,14,17},
					{17,16,15,24,21,18, 0, 1, 2,38,41,44}
};		
char color[] = "wygrbo";
//enum side { U, D, L, F, R, B};
/*U : 0, D: 1, L:2, F:3, R:4, B:5 */
int trans[27];

/*reset cube color*/
void reset();
void rotate(int);

int main()
{
	int test;
	cin >> test;
	trans['U' - 'A'] = 0;
	trans['D' - 'A'] = 1;
	trans['L' - 'A'] = 2;
	trans['F' - 'A'] = 3;
	trans['R' - 'A'] = 4;
	trans['B' - 'A'] = 5;

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				mapping[cube[i][j][k]] = color[i];
			
	while (test--)
	{
		reset();

		int n;
		cin >> n;
		char op[4];
		for (int i = 0; i < n; i++)
		{
			cin >> op;
			rotate(trans[op[0]-'A']);

			if (op[1] != '+')
			{
				rotate(trans[op[0] - 'A']);
				rotate(trans[op[0] - 'A']);
			}
		}
		
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << mapping[cube[0][i][j]];
			cout << "\n";
		}
	}

	return 0;
}

/*

00 01 02  0 1 2
10 11 12  3 4 5
20 21 22  6 7 8
*/

void rotate(int s)
{
	char temp[12];
	for (int i = 0; i < 12; i++)
		temp[i] = mapping[side[s][i]];

	for (int i = 3; i < 15; i++)
		mapping[side[s][i - 3]] = temp[i % 12];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			temp[i * 3 + j] = mapping[cube[s][i][j]];

	mapping[cube[s][0][0]] = temp[6];
	mapping[cube[s][0][1]] = temp[3];
	mapping[cube[s][0][2]] = temp[0];
	mapping[cube[s][1][2]] = temp[1];
	mapping[cube[s][2][2]] = temp[2];
	mapping[cube[s][2][1]] = temp[5];
	mapping[cube[s][2][0]] = temp[8];
	mapping[cube[s][1][0]] = temp[7];
}

void reset()
{
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				mapping[cube[i][j][k]] = color[i];
}