/* https://www.acmicpc.net/problem/2809 */ 

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
	public static int d = 1;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int len = Integer.parseInt(br.readLine());
		String s = br.readLine();
		boolean[] bitmap = new boolean[len]; 
		Arrays.fill(bitmap, false);
		Integer[] suffix = new Integer[len];
		int[] group = new int[len];
		int[] temp = new int[len];
		
		for(int i = 0; i < len; i++)
		{
			suffix[i] = i;
			group[i] = s.charAt(i);
			temp[i] = 0;
		}
		
		//making suffix array
		Comparator<Integer> comp = new Comparator<Integer>() {
			public int compare(Integer a, Integer b)
			{
				if(group[a] != group[b])
					if(group[a] < group[b])
						return -1;
					else
						return 1;
				
				a += d;
				b += d;
				
				if(a < len && b  < len)
				{
					if(group[a] == group[b])
						return 0;
					else if(group[a] < group[b])
						return -1;
					else
						return 1;
				}
				else
					return a > b  ? -1 : a == b ? 0 : 1;
			}
		};
		
		for(d = 1; ; d *= 2)
		{
			Arrays.sort(suffix, comp);
			Arrays.fill(temp, 0);
			
			for(int i = 1; i<len; i++)
				temp[i] = temp[i-1] - comp.compare(suffix[i-1], suffix[i]);
			
			for(int i = 0; i<len; i++)
				group[suffix[i]] = temp[i];
			
			if(temp[len-1] == len-1)
				break;
		}
		
		
		int m = Integer.parseInt(br.readLine());
		Tile[] tile = new Tile[m];
		int[] intervalcheck = new int[len];
		Arrays.fill(intervalcheck, -1);
		
		String t;
		for(int i = 0; i < m; i++)
		{
			t = br.readLine();
			tile[i] = new Tile(t.length(), getInterval(suffix, t, s));
			//System.out.println(tile[i].interval[0] + " " +tile[i].interval[1]);
		}
		
		for(int i = 0; i < m; i++)
		{
			/* find longest tile that contains a suffix within its interval */
			int start = tile[i].interval[0];
			int end = tile[i].interval[1];
			
			if(start >= len || end >=len)
				continue;
			
			for(int j = start; j<=end; j++)
			{
				if(intervalcheck[j] != -1)
				{
					if(tile[intervalcheck[j]].length < tile[i].length)
						intervalcheck[j] = i;
				}
				else
					intervalcheck[j] = i;
			}
		}
		
		for(int i = 0; i < len; i++)
		{
			if(intervalcheck[i] == -1)
				continue;
			
			int start = suffix[i];
			int range = tile[intervalcheck[i]].length;
			for(int j = start; j < start + range; j++)
				bitmap[j] = true;
		}
		
		int count = 0;
		for(int i = 0; i< len; i++)
			if(!bitmap[i])
				count++;
		System.out.println(count);
	}
	
	public static int[] getInterval(Integer[] suffix, String str, String s)
	{
		/* using binary search to find the range of the interval */
		
		int[] interval = {0, 0};
		int l = 0, r = suffix.length;
		int mid;
		int result;
		
		/*find starting point*/
		while(l < r)
		{
			mid = (l + r)/2;
			result = str.compareTo(s.substring(suffix[mid]));
			if(result > 0)
				l = mid + 1;
			else if(result == 0)
			{
				l = mid;
				break;
			}
			else
				r = mid;
		}
		interval[0] = l;
		
		/*increment the last character of str by 1.*/
		char[] temp = str.toCharArray();
		temp[str.length() -1]++;
		str = String.valueOf(temp);
		
		/*find ending point*/
		r = suffix.length;
		while(l < r)
		{
			mid = (l + r)/2;
			result = str.compareTo(s.substring(suffix[mid]));
			if(result < 0)
				r = mid;
			else if(result == 0)
			{
				r = mid;
				break;
			}
			else
				l = mid + 1;
		}
		/*this r position is for the incremented str. So -1 is needed*/
		interval[1] = r-1;
		
		return interval;
	}
}

class Tile
{
	int length;
	int[] interval;
	
	public Tile(int length, int[] interval)
	{
		this.length = length;
		this.interval = interval;
	}
}