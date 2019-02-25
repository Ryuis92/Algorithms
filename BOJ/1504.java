/* https://www.acmicpc.net/problem/1504 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class Main {
	 public static int shortest(ArrayList<edge>[] adj, int start, int target) {
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
	    	return ans[target];
	    }
	
	public static void main(String[] args) throws Exception {
    	int vertex_num;
    	int edge_num;
    	int must1, must2;
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	String temp = br.readLine();
    	String[] tokens = temp.split(" ");
    	
    	vertex_num = Integer.parseInt(tokens[0]);
    	edge_num = Integer.parseInt(tokens[1]);
    	
    	ArrayList<edge>[] adj = new ArrayList[vertex_num];
    	for(int i = 0; i < vertex_num; i++)
    		adj[i] = new ArrayList();
    		
    	int a, b, weight;
    	for(int i = 0; i < edge_num; i++)
    	{
    		temp = br.readLine();
    		tokens = temp.split(" ");
    		
    		a = Integer.parseInt(tokens[0]);
    		b = Integer.parseInt(tokens[1]);
    		weight = Integer.parseInt(tokens[2]);
    		
    		a--;
    		b--;
    		
    		adj[a].add(new edge(b,weight));
    		adj[b].add(new edge(a,weight));
    	}
    	temp = br.readLine();
    	tokens = temp.split(" ");
    	must1 = Integer.parseInt(tokens[0]) - 1;
    	must2 = Integer.parseInt(tokens[1]) - 1;
    	
    	int first, second, third;
    	int first2, second2, third2;
    	int ans, ans2;
    	first = shortest(adj, 0, must1);
    	second = shortest(adj, must1, must2);
    	third = shortest(adj, must2, vertex_num-1);
    	
    	first2 = shortest(adj, 0, must2);
    	second2 = shortest(adj, must2, must1);
    	third2= shortest(adj, must1, vertex_num-1);
    	
    	if(first == Integer.MAX_VALUE || second == Integer.MAX_VALUE || third == Integer.MAX_VALUE)
    		ans = -1;
    	else
    		ans = first + second + third;
    	
    	if(first2 == Integer.MAX_VALUE || second2 == Integer.MAX_VALUE || third2 == Integer.MAX_VALUE)
    		ans2 = -1;
    	else
    		ans2 = first2 + second2 + third2;
    	
    	if(ans == -1 && ans2 == -1)
    		System.out.println(-1);
    	else if(ans == -1)
    		System.out.println(ans2);
    	else if(ans2 == -1)
    		System.out.println(ans);
    	else
    		System.out.println(Math.min(ans, ans2));
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