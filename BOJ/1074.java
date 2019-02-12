/* https://www.acmicpc.net/problem/1074 */
import java.util.Scanner;

public class Main 
{	
	public int last = 0;
	public int n;
	int col;
	int row;
	
	public void solve() 
	{
		Scanner sc = new Scanner(System.in);
		int len;
		this.n = sc.nextInt();
		this.row = sc.nextInt();
		this.col = sc.nextInt();
		
		len = (int)(Math.pow(2, n));
		System.out.println(search(len, this.row, this.col));
		
	}
	
	public int search(int len, int row, int col) 
	{
		if(len == 1)
			return 0;
		
		len /= 2;
		
		if(row >= len && col >= len)
			return search(len, row-len, col-len) + 3*len*len;
		else if(row >= len && col < len)
			return search(len, row-len, col) + 2*len*len;
		else if (row < len && col >= len)
			return search(len, row, col-len) + len*len;
		else
			return search(len, row, col);
	}
	
	public static void main(String[] args) 
	{
		Main m = new Main();
		m.solve();
	}
}

/////////////////////////////////////////////////////////////////////////
/*
Below are the codes that is another way of implementing the same thing as above

*/
import java.util.Scanner;

public class Main 
{	
	public int last = 0;
	public int n;
	int col;
	int row;
	
	public void solve() 
	{
		Scanner sc = new Scanner(System.in);
		int len;
		this.n = sc.nextInt();
		this.row = sc.nextInt();
		this.col = sc.nextInt();
		
		len = (int)(Math.pow(2, n));
		search(0, 0, len-1, len-1);
		
	}
	
	public void search(int r1, int c1, int r2, int c2) 
	{
		if(c2 - c1 + 1 > 2) 
		{
			int len = (int)((c2-c1 + 1)/2);
			for(int i = 0; i<2; i++)
				for(int j = 0; j < 2; j++) 
				{
					search(r1 + len * i, c1 + len * j, r1 + len * (1 + i) - 1 , c1 + len * (j + 1) - 1);
				}
			
		}
		else 
		{
			int col, row;
			for(int i = 0; i<2; i++)
				for(int j = 0; j < 2; j++) 
				{
					row = r1 + i;
					col = c1 + j;
					if (row == this.row && col == this.col)
					{
						System.out.println(last);
						return;
					}
					last++;
				}
		}
	}
	
	
	public static void main(String[] args) 
	{
		Main m = new Main();
		m.solve();
	}
}