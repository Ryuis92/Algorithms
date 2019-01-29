/* https://www.acmicpc.net/problem/10871 */
import java.util.Scanner;

public class Main 
{
	public void solve() 
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = sc.nextInt();
		int[] arr = new int[n];
		int temp;
		for(int i = 0; i < n; i++)
		{
			temp = sc.nextInt();
			if(temp < x)
				arr[i] = temp;
			else
				arr[i] = -1;
		}
		for(int i = 0; i < n; i++) 
		{
			if(arr[i] > -1)
				System.out.print(arr[i] + " ");
		}
	}
	
	public static void main(String[] args) 
	{
		Main m = new Main();
		m.solve();
	}
}