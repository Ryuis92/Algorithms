/* https://www.acmicpc.net/problem/10217 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String del = " ";
		String[] token;
		int test;
		int port_num;
		int budget;
		int ticket_num;
		
		token = br.readLine().split(del);
		test = Integer.parseInt(token[0]);
		
		while(test-- > 0)
		{
			token = br.readLine().split(del);
			port_num = Integer.parseInt(token[0]);
			budget = Integer.parseInt(token[1]);
			ticket_num = Integer.parseInt(token[2]);
			ArrayList<Edge>[] adj = new ArrayList[port_num];
			int[][] dp= new int[port_num][budget+1];
			
			
			for(int i = 0; i <port_num; i++)
				adj[i] = new ArrayList();
			
			for(int i = 0; i <port_num; i++)
				for(int j = 0; j<budget+1; j++)
					dp[i][j] = Integer.MAX_VALUE;
			
			int from, to, cost, time;
			for(int i =0; i<ticket_num; i++)
			{
				token = br.readLine().split(del);
				from = Integer.parseInt(token[0]) - 1;
				to = Integer.parseInt(token[1]) - 1;
				cost = Integer.parseInt(token[2]);
				time = Integer.parseInt(token[3]);
				
				adj[from].add(new Edge(to, cost, time));
			}
			
			dijkstra(adj, dp);
			int ans = Integer.MAX_VALUE;
			for(int i = 0; i<dp[port_num-1].length; i++)
			{
				if(dp[port_num-1][i] != Integer.MAX_VALUE && dp[port_num-1][i] < ans)
					ans = dp[port_num-1][i];
			}
			
			if(ans == Integer.MAX_VALUE)
				System.out.println("Poor KCM");
			else
				System.out.println(ans);
		}
	}
	
	public static void dijkstra(ArrayList<Edge>[] adj, int[][] dp) 
	{
		int start = 0;
		PriorityQueue<Edge> pq = new PriorityQueue(); 
		pq.offer(new Edge(0, 0, 0));
		dp[0][0] =0;
		
		Edge curr;
		while(!pq.isEmpty())
		{
			curr = pq.poll();
			if(dp[curr.to][curr.cost] < curr.time)
				continue;
			
			for(Edge e: adj[curr.to])
			{
				if(curr.cost + e.cost >= dp[0].length)
					continue;
				
				if(dp[e.to][curr.cost + e.cost] > curr.time + e.time)
				{
					dp[e.to][curr.cost + e.cost] = curr.time + e.time;
					pq.offer(new Edge(e.to, curr.cost + e.cost, curr.time + e.time));
				}
			}
		}
	}
}

class Edge implements Comparable<Edge>
{
	int to;
	int cost;
	int time;
	
	public Edge(int to, int cost, int time) 
	{
		this.to = to;
		this.cost = cost;
		this.time = time;
	}
	
	public int compareTo(Edge e) 
	{
		if(this.time > e.time)
			return 1;
		else
			return -1;
	}
}

/*
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String del = " ";
		String[] token;
		int test;
		int port_num;
		int budget;
		int ticket_num;
		
		token = br.readLine().split(del);
		test = Integer.parseInt(token[0]);
		
		while(test-- > 0)
		{
			token = br.readLine().split(del);
			port_num = Integer.parseInt(token[0]);
			budget = Integer.parseInt(token[1]);
			ticket_num = Integer.parseInt(token[2]);
			ArrayList<Edge>[] adj = new ArrayList[port_num];
			int[][] dp= new int[port_num][budget+1];
			
			
			for(int i = 0; i <port_num; i++)
				adj[i] = new ArrayList();
			
			for(int i = 0; i <port_num; i++)
				for(int j = 0; j<budget+1; j++)
					dp[i][j] = Integer.MAX_VALUE;
			
			int from, to, cost, time;
			for(int i =0; i<ticket_num; i++)
			{
				token = br.readLine().split(del);
				from = Integer.parseInt(token[0]) - 1;
				to = Integer.parseInt(token[1]) - 1;
				cost = Integer.parseInt(token[2]);
				time = Integer.parseInt(token[3]);
				
				adj[from].add(new Edge(to, cost, time));
			}
			
			dijkstra(adj, dp);
		}
	}
	
	public static void dijkstra(ArrayList<Edge>[] adj, int[][] dp) 
	{
		int start = 0;
		PriorityQueue<Edge> pq = new PriorityQueue(); 
		pq.offer(new Edge(0, 0, 0));
		dp[0][0] = 0;
	
		Edge curr;
		int ans = Integer.MAX_VALUE;
		while(!pq.isEmpty())
		{
			curr = pq.poll();
			if(ans <= dp[curr.to][curr.cost])
				continue;
			
			for(Edge e: adj[curr.to])
			{
				int cost = curr.cost + e.cost;
				int time = dp[curr.to][curr.cost] + e.time;
				if(cost >= dp[0].length)
					continue;
				
				if(ans <= time)
					continue;
				if(e.to == adj.length -1)
				{
					ans = time;
					continue;
				}
				
				if(dp[e.to][cost] > time)
				{
					if(dp[e.to][cost] == Integer.MAX_VALUE)
						pq.offer(new Edge(e.to, cost, time));
					dp[e.to][cost] = time;
				}
			}
		}
		
		if(ans == Integer.MAX_VALUE)
			System.out.println("Poor KCM");
		else
			System.out.println(ans);
	}
}

class Edge implements Comparable<Edge>
{
	int to;
	int cost;
	int time;
	
	public Edge(int to, int cost, int time) 
	{
		this.to = to;
		this.cost = cost;
		this.time = time;
	}
	
	public int compareTo(Edge e) 
	{
		if(this.cost > e.cost)
			return 1;
		else
			return -1;
	}
}



*/