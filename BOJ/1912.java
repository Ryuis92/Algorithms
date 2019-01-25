/*https://www.acmicpc.net/problem/1912*/
import java.util.Scanner;
import java.util.ArrayList;

class Main
{
	public int solve()
	{
		Scanner sc = new Scanner(System.in);
		ArrayList<Integer> arr = new ArrayList<Integer>();
		int num = sc.nextInt();
        int result;
		ArrayList<Integer> OPT = new ArrayList<Integer>(num);
            
		for(int i = 0; i< num ; i++)
			arr.add(sc.nextInt());

		OPT.add(arr.get(0));
        result = arr.get(0);
		for(int i = 1; i < num; i++)
		{
			OPT.add(Math.max(arr.get(i), OPT.get(i-1) + arr.get(i)));
            result = Math.max(result, OPT.get(i));
		}
            
		return result;
    }

	public static void main(String[] args)
	{
		Main a = new Main();
		System.out.println(a.solve());
	}