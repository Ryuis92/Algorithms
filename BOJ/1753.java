/* https://www.acmicpc.net/problem/1753 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;


public class Main {
    public static int[] shortest(ArrayList<edge>[] adj, int start) {
    	PriorityQueue<edge> pq = new PriorityQueue();
    	int[] ans = new int[adj.length];
    	for(int i = 0; i<ans.length; i++)
    		ans[i] = Integer.MAX_VALUE;
    	ans[start] = 0;
    	
    	pq.offer(new edge(start, 0));
    	edge curr;
    	while(!pq.isEmpty()) {
    		curr = pq.poll();
    		
    		for(edge e: adj[curr.to]) {
    			if(ans[e.to] > ans[curr.to] + e.weight) {
    				ans[e.to] = ans[curr.to] + e.weight;
    				pq.offer(new edge(e.to, ans[e.to]));
    			}
    		}
    	}
    	
    	return ans;
    }
	
	public static void main(String[] args) throws Exception {
    	int vertex_num;
    	int edge_num;
    	int start;
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	String temp = br.readLine();
    	String[] tokens = temp.split(" ");
    	
    	vertex_num = Integer.parseInt(tokens[0]);
    	edge_num = Integer.parseInt(tokens[1]);
    	start = Integer.parseInt(br.readLine());
    	start--;
    	
    	ArrayList<edge>[] adj = new ArrayList[vertex_num];
    	for(int i = 0; i < vertex_num; i++)
    		adj[i] = new ArrayList();
    		
    	int[] nodes = new int[vertex_num];
    	
    	int from, to, weight;
    	for(int i = 0; i < edge_num; i++)
    	{
    		temp = br.readLine();
    		tokens = temp.split(" ");
    		
    		from = Integer.parseInt(tokens[0]);
    		to = Integer.parseInt(tokens[1]);
    		weight = Integer.parseInt(tokens[2]);
    		
    		from--;
    		to--;
    		
    		adj[from].add(new edge(to,weight));
    	}
  
    	int[] ans = shortest(adj, start);
    	for(int a : ans)
    		if(a == Integer.MAX_VALUE)
    			System.out.println("INF");
    		else
    			System.out.println(a);
    }
}

class edge implements Comparable<edge>
{
	public int to;
	public int weight;

	public edge(int to, int weight) 
	{
		this.to = to;
		this.weight = weight;
	}
	
	public int compareTo(edge a) 
	{
		if (a.weight > this.weight)
			return -1;
		else
			return 1;
		
	}
}
