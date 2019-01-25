/*https://www.acmicpc.net/problem/9461*/

import java.util.Scanner;
import java.util.ArrayList;

class Main
{
    Scanner sc;
    ArrayList<Long> OPT;
    
    public Main(Scanner sc, ArrayList<Long> OPT)
    {
        this.sc = sc;
        this.OPT = OPT;
    }
    
	public long solve()
	{
		int num = this.sc.nextInt();
	    if (OPT.size() == 0)
        {
            OPT.add(1L);
            OPT.add(1L);
            OPT.add(1L);
            OPT.add(2L);
            OPT.add(2L);
        }
        
        for(int i = OPT.size(); i<num; i++)
            OPT.add((long)(OPT.get(i-1)) + (long)(OPT.get(i-5)));
          
		return OPT.get(num-1);
    }

	public static void main(String[] args)
	{
		Main a = new Main(new Scanner(System.in), new ArrayList<Long>());
         
        int line = a.sc.nextInt();
        while(line != 0)
        {
            line--;
            System.out.println(a.solve());
        }
        a.sc.close();
	}
}