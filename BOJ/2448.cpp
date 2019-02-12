/* https://www.acmicpc.net/problem/2448 */
#include<iostream>

using namespace std;

int main() 
{
	int num;
	bool** map;

	cin >> num;
	
	int temp = num / 3;
	int k = 1;
	while (temp != 1) 
	{
		temp /= 2;
		k *= 2;
	}

	// the logest line of star map. it depends on k of 3*2^k
	int len = k * 6 - 1;
	map = new bool*[num];
	
	for (int i = 0; i <num; i++)
	{
		map[i] = new bool[len];
		for (int j = 0; j < len; j++)
			map[i][j] = false;
	}
	// first points the first index of * in the last line, last likewise.	
	int mid = (len - 1) / 2;
	int first = mid;
	int last = mid;
	int line = 3;

	//initailize 3 basic lines.
	map[0][(len - 1) / 2] = true;
	map[1][--first] = true;
	map[1][++last] = true;
	

	first--;
	last++;

	for (int i = first; i <= last; i++)
		map[2][i] = true;


	while(line != num)
	{
		/*
		1. The building pattern of this star map is like this. First build 3 basic lines. 
		2. This will be a unit of this star map. attach two units beneath the unit. 
		3. Now these 3 units become the basic unit. Repeat from #1

		To implement this, you have to copy stars from above. So you need another first and last to point
		where you're copying.

		
		*/

		int temp_f = mid;
		int temp_l = mid;
		for (int i = line; i < line + line; i++)
		{
			first--;
			last++;

			for (int j = temp_f; j <= temp_l; j++)
			{
				map[i][first + j - temp_f] = map[i - line][j];
				map[i][last - j + temp_f] = map[i - line][j];
			}
			temp_f--;
			temp_l++;
		}
		line *= 2;
	}

	//print stars
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (map[i][j])
				cout << "*";
			else
				cout << " ";
		}
		delete[] map[i];
		cout << endl;
	}

	delete[] map;
	return 0;
}


//////////////////////////////
#include<iostream>

using namespace std;

void stars(int s, int e, int line);
bool** map;
int main() 
{
	int num;
	cin >> num;

	int len = num * 2 - 1;
	
	map = new bool*[num];
	
	for (int i = 0; i < num; i++)
		map[i] = new bool[len];

	for (int i = 0; i < num; i++)
		for (int j = 0; j < len; j++)
			map[i][j] = false;


	stars(0, (len-1)/2, num);

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (map[i][j])
				cout << "*";
			else
				cout << " ";
		}
		delete[] map[i];
		cout << endl;
	}
	delete[] map;
	return 0;
}

void stars(int s, int e, int line) 
{
	if (line == 3) 
	{
		map[s][e] = true;
		map[s + 1][e + 1] = true;
		map[s + 1][e - 1] = true;
		
		for (int i = 0; i < 5; i++)
			map[s + 2][e - 2 + i] = true;
	}
	else 
	{
		line /= 2;
		
		stars(s, e, line);
		stars(s+line, e - line,line);
		stars(s+line, e+ line,line);
	}
}