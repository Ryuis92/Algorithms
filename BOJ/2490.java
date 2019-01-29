/* https://www.acmicpc.net/problem/2490 */
import java.util.Scanner;

public class Main 
{
	public void solve() 
	{
		Scanner sc = new Scanner(System.in);
		int line = 3;
		while(line-- > 0) 
		{
			int front = 0;
			
			for(int i = 0; i<4; i++) 
			{
				if(sc.nextInt() == 0)
					front++;
			}			
			switch(front) 
			{
				case 0:
					System.out.println("E");
					break;
				case 1:
					System.out.println("A");
					break;
				case 2:
					System.out.println("B");
					break;
				case 3:
					System.out.println("C");
					break;
				default:	
					System.out.println("D");
			}
		}
	}
	
	public static void main(String[] args) 
	{
		Main m = new Main();
		m.solve();
	}

}
