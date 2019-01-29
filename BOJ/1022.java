/* https://www.acmicpc.net/problem/1022 */
import java.util.Scanner;

public class Main 
{
	public void solve() 
	{
		Scanner sc = new Scanner(System.in);
		int r1, c1, r2, c2;
		r1 = sc.nextInt();
		c1 = sc.nextInt();
		r2 = sc.nextInt();
		c2 = sc.nextInt();
		int[][] map = new int[r2-r1+1][c2-c1+1];
		int curr;
		int col;
		int row;
		int max = 0;
		int div = 1;
		for(int i = 0; i<map.length; i++) 
			for(int j = 0; j<map[i].length; j++)
			{
				row = r1 + i;
				col = c1 + j;
				if(row>=0 && col>=0) 
				{
					if(row >= col) 
						curr = (2*(row+1)-1)*(2*(row+1)-1) - (row-col);
					else
						curr = (2*(col+1)-1) * (2*(col+1)-1) - 3*(2*(col+1)-2) - (col+row);
				}
				else if(row >= 0 && col <= 0) 
				{
				
					if(row > -col) 
						curr = (2*(row+1)-1)*(2*(row+1)-1) - (row-col);
					else 
						curr = (2*(-col+1)-1) * (2*(-col+1)-1) - (2*(-col+1)-2) - (-col-row);
				}
				else if(row <= 0 && col >= 0)
				{
					
					if(-row > col) 
						curr = (2*(-row+1)-1)*(2*(-row+1)-1) - 2*(2*(-row+1) -2) - (-row+col);
					else 
						curr = (2*(col+1)-1) * (2*(col+1)-1) - 3*(2*(col+1)-2) - (col+row);
				}
				else
				{
					if(-row >= -col) 
						curr = (2*(-row+1)-1)*(2*(-row+1)-1) - 2*(2*(-row+1) -2) - (-row+col);
					else 
						curr = (2*(-col+1)-1) * (2*(-col+1)-1) - (2*(-col+1)-2) - (-col-row);
				}
				map[i][j] = curr;
				max = Math.max(curr, max);
			}
		
		while(max > 9)
		{
			max /=10;
			div++;
		}
		for(int i = 0; i<map.length; i++) 
		{
			for(int j = 0; j<map[i].length; j++) 
			{
				System.out.print(String.format("%" + div + "s", map[i][j]) + " ");
			}
			System.out.println();
		}
		
	}
	
	public static void main(String[] args) 
	{
		Main m = new Main();
		m.solve();
	}
}

/*
					  row  col
 (2n-1)^2 			= n-1,(n-1)
 (2n-1)^2 - (2n-2)  = n-1 ,-n+1
 (2n-1)^2 - 2(2n-2) = -n+1, -n+1
 (2n-1)^2 - 3(2n-2) = -(n-1), n-1
*/