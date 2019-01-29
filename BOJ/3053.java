/* https://www.acmicpc.net/problem/3053 */

import java.util.Scanner;

public class Main 
{
	public void solve() 
	{
		Scanner sc = new Scanner(System.in);
		int radius = sc.nextInt();
		
		System.out.println(radius*radius*Math.PI);
		System.out.println((double)radius*radius*2 );
	
	}
	
	public static void main(String[] args) 
	{
		Main m = new Main();
		m.solve();
	}
}