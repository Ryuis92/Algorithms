/* https://www.acmicpc.net/problem/11657 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String del = " ";
		int city_num;
		int line_num;
		Edge[] arr;
		
		String[] token = br.readLine().split(del);
		city_num = Integer.parseInt(token[0]);
		line_num = Integer.parseInt(token[1]);
		arr = new Edge[line_num];
		
		int from, to, weight;
		for(int i = 0; i <line_num; i++)
		{
			token = br.readLine().split(del);
			from = Integer.parseInt(token[0]) - 1;
			to = Integer.parseInt(token[1]) - 1;
			weight = Integer.parseInt(token[2]);
			
			arr[i] = new Edge(from, to, weight);
		}
		
		int[] ans = bellan_ford(arr, city_num);
		if(ans[0] == -Integer.MAX_VALUE)
			System.out.println(-1);
		else
			for(int i = 1; i<ans.length; i++)
				if (ans[i] == Integer.MAX_VALUE)
					System.out.println(-1);
				else
					System.out.println(ans[i]);
		
	}
	
	public static int[] bellan_ford(Edge[] arr, int city_num) 
	{
		int[] cost = new int[city_num];
		
		for(int i = 1; i <city_num; i++)
			cost[i] = Integer.MAX_VALUE;
		cost[0] = 0;
		
		Edge now;
		for(int i = 0; i< city_num; i++)
			for(int j = 0; j<arr.length; j++)
			{
				now = arr[j];
				if(cost[now.from] != Integer.MAX_VALUE && cost[now.to] > cost[now.from] + now.weight)
					cost[now.to] =  cost[now.from] + now.weight;
			}
		
		for(int j = 0; j<arr.length; j++)
		{
			now = arr[j];
			if(cost[now.from] != Integer.MAX_VALUE && cost[now.to] > cost[now.from] + now.weight)
			{
				cost[0] = -Integer.MAX_VALUE;
				break;
			}
		}
		
		return cost;
	}
}

class Edge
{
	int from;
	int to;
	int weight;
	
	public Edge(int from,int to, int weight) 
	{
		this.from = from;
		this.to = to;
		this.weight = weight;
	}
}