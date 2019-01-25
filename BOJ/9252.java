/* https://www.acmicpc.net/problem/9252 */
import java.util.Scanner;

public class Main 
{
	public String solve() 
	{
		Scanner sc = new Scanner(System.in);
		String a = sc.nextLine();
		String b = sc.nextLine();
		int col = a.length() + 1;
		int row = b.length() + 1;
		StringBuilder result = new StringBuilder();
		int[][] opt = new int[col][row];
		int[][] match = new int[col][row];
		for(int i = 1; i < col; i++)
			for(int j = 1; j<row; j++) 
			{
				if(a.charAt(i-1) == b.charAt(j-1))
				{
					opt[i][j] = opt[i-1][j-1] + 1;
					match[i][j] = 1;
				}
				else if (opt[i-1][j] >  opt[i][j-1])
				{
					opt[i][j] = opt[i-1][j];
					match[i][j] = 2;
				}
				else 
				{
					opt[i][j] = opt[i][j-1];
					match[i][j] = 3;
				}
			}
		
		int i = col-1;
		int j = row-1;
		while(true) 
		{
			if(match[i][j] == 1) 
			{
				result.append(a.charAt(i-1));
				i -= 1;
				j -= 1;
			}
			else if(match[i][j] == 2) 
			{
				i -= 1;
			}
			else if(match[i][j] == 3) 
			{
				j -= 1;
			}
			else
				break;
		}
		
		sc.close();
		return result.reverse().toString();
	}
	
	
	public static void main(String[] args) 
	{
		Main m = new Main();
		String result = m.solve();
		System.out.println(result.length());
		System.out.println(result);
	}

}
