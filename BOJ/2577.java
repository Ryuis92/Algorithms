/* https://www.acmicpc.net/problem/2577 */
import java.util.Scanner;

public class Main 
{
	public void solve() 
	{
		Scanner sc = new Scanner(System.in);
		int a,b,c;
		int mult;
		int one;
		int[] frequency = new int[10];
		a = sc.nextInt();
		b = sc.nextInt();
		c = sc.nextInt();
		
		mult = a * b * c;
		while(mult > 0) 
		{
			one = mult % 10;
			frequency[one]++;
			mult /= 10;
		}
		
		for(int i = 0; i < frequency.length; i++)
			System.out.println(frequency[i]);
	}
	
	public static void main(String[] args) 
	{
		Main m = new Main();
		m.solve();
	}
}