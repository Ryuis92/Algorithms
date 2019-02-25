/* https://www.acmicpc.net/problem/1865 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
	public static boolean shortest(ArrayList<Edge>[] adj) 
	{
		int start = 0;
	
		int[] cost = new int[adj.length];
		
		for(int i = 0; i <cost.length; i++)
			cost[i] = Integer.MAX_VALUE;
		cost[start] = 0;
		
		for(int i = 0; i<cost.length; i++)
			for(int j = 0; j<cost.length; j++)
				for(Edge e: adj[j]) 
				{
					if(cost[j] != Integer.MAX_VALUE && cost[e.to] > cost[j] + e.weight)
						cost[e.to] = cost[j] + e.weight;
				}
		for(int j = 0; j<cost.length; j++)
			for(Edge e: adj[j]) 
			{
				if(cost[j] != Integer.MAX_VALUE && cost[e.to] > cost[j] + e.weight)
					return true;
			}
		
		return false;
	}
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());
		
		while(test-- > 0)
		{
			ArrayList<Edge>[] adj;
			int vertex_num, edge_num, hole_num;
			String[] token = br.readLine().split(" ");
			vertex_num = Integer.parseInt(token[0]);
			edge_num = Integer.parseInt(token[1]);
			hole_num = Integer.parseInt(token[2]);
			
			adj = new ArrayList[vertex_num];
			for(int i = 0; i < vertex_num; i++)
				adj[i] = new ArrayList();
			
			
			int a, b, w;
			for(int i = 0; i < edge_num; i++)
			{
				token = br.readLine().split(" ");
				a = Integer.parseInt(token[0]) - 1;
				b = Integer.parseInt(token[1]) - 1;
				w = Integer.parseInt(token[2]);
				
				adj[a].add(new Edge(b, w));
				adj[b].add(new Edge(a, w));
			}
			
			for(int i = 0; i < hole_num; i++)
			{
				token = br.readLine().split(" ");
				a = Integer.parseInt(token[0]) - 1;
				b = Integer.parseInt(token[1]) - 1;
				w = Integer.parseInt(token[2]);
				
				adj[a].add(new Edge(b, -w));
			}
			
			if(shortest(adj))
				System.out.println("YES");
			else
				System.out.println("NO");
		}
		br.close();
	}
}

class Edge
{
	int to;
	int weight;
	
	public Edge(int to, int weight) 
	{
		this.to = to;
		this.weight = weight;
	}
}