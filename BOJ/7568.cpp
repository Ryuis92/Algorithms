/* https://www.acmicpc.net/problem/7568 */ 

#include<iostream>
#include<vector>
using namespace std;

class body 
{
public:
	int weight, height;

	body(int w, int h) :weight(w), height(h)
	{

	}

	~body() 
	{
	}
};

int main() 
{
	int n;
	cin >> n;
	int w, h;
	int count;
	vector<body> list;
	
	for (int i = 0; i < n; i++)
	{
		cin >> w >> h;
		list.push_back(body(w, h));
	}

	for (int i = 0; i < n; i++)
	{
		count = 0;
		for (int j = 0; j < n; j++)
		{
			if (list[i].weight < list[j].weight && list[i].height < list[j].height)
				count++;
			
		}
		cout << count + 1 <<" ";
	}
	cout << endl;
	return 0;
}

