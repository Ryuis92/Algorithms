/* https://www.acmicpc.net/problem/11478 */

import java.util.Arrays;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String[] suffix;
		int[] lcp;
		String s = sc.nextLine();
		suffix = new String[s.length()];
		lcp = new int[s.length()];
		
		for(int i = 0; i <s.length(); i++)
			suffix[i] = s.substring(i);
		
		Arrays.sort(suffix);
		Arrays.fill(lcp, -1);
		lcp[0] = 0;
		int short_len;
		for(int i = 1; i <s.length(); i++)
		{
			short_len = Math.min(suffix[i].length(), suffix[i-1].length());
			for(int j = 0; j< short_len; j++)
			{
				if(suffix[i].charAt(j) != suffix[i-1].charAt(j))
				{
					lcp[i] = j;
					break;
				}
			}
			if(lcp[i] == -1)
				lcp[i] = short_len;
		}
		
		int ans = 0;
		for(int i =0; i<suffix.length; i++) 
		{
			ans += suffix[i].length(); //This can be replaced with N = s.length(). N(N+1)/2
			ans -= lcp[i];
		}
		System.out.println(ans);
	}
}
	

/*
This can be done easily like below

import java.util.Scanner;
import java.util.HashSet;
import java.util.Set;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		Set<String> set = new HashSet();
		String s = sc.nextLine();
		
		for(int i = 0;i < s.length(); i++)
			for(int j = 0; j <s.length() && j+i <s.length(); j++)
				set.add(s.substring(j, j+i+1));
			
		System.out.println(set.size());
	}
}

But this implementation is somewhat slower than the original one. Since this is O(n*n) time algorithm and the other O(nlogn) time.

The original one is using suffixes of a String. a subsequence or substring of a string is the prefix of a suffix.

For example, let's say input = "ababc", Suffixes are like below.

ababc
babc
abc
bc
c

To find longest common prefix of adjacent two suffixes order these suffixes alphabetically.

suffix | LCP
---------------
ababc  |  X(0)
abc    |  ab(2)
babc   |  X(0)
bc     |  b(1)
c      |  X(0)

You can compute the total number of subsequence of a string as N*(N+1)/2.
With LCP, we can also compute duplicated subsequences. 

abc, ababc has LCP of 2, which means two duplications: a, ab
likewise babc, bc, LCP of 1, has one duplication: b

So, With N = 5, the total number of substrings is 15, and the number of duplicates is the total of LCP, 3
Now we get the answer 15 - 3 = 12
*/