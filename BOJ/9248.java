/* https://www.acmicpc.net/problem/9248
ref: https://kks227.blog.me/221028710658
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
	public static int d = 1;
	public static char[] s;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		s = br.readLine().toCharArray();
		int len = s.length;
		
		Integer[] suffix_arr = new Integer[len];
		int[] group = new int[len];
		int[] LCP = new int[len];
		
		for(int i = 0; i < len; i++)
		{
			/*
			Init
			At first, suffix array is grouped by its first letter.
			*/
			suffix_arr[i] = i;
			group[i] = s[i];
			LCP[i] = -1;
		}
		
		Comparator<Integer> comp = new Comparator<Integer>() {
			/* comparator should be sysmetric. It must return each 1, 0, -1 for the proper cases.*/
			/* This is for sorting suffix array. It sorts the array with group */
			public int compare(Integer a, Integer b) {
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
		
		int[] temp = new int[len];

		for(d = 1; ; d *= 2)
		{
			Arrays.sort(suffix_arr, comp);
			Arrays.fill(temp, 0);
			

			/*
			 With sorted suffix array, you now regroup them. It's sorted in ascending order, so you know that suffix_arr[i] <= suffix_arr[i+1].
			 Now you want to know if they are in same group or not. If the two suffixes are the same in the first d letters, then the compare function will return 0.
			 Otherwise, it will return -1.

			 You should keep in mind that temp[i] means the group number of suffix_arr[i]. That's why group[suffix_arr[i]] = temp[i]; works.

			*/
			for(int i = 0; i < len-1; i++)
				temp[i+1] = temp[i] - comp.compare(suffix_arr[i], suffix_arr[i+1]);
			
			for(int i = 0; i < len; i++)
				group[suffix_arr[i]] = temp[i];
			
			/* Escape condition. This means that all of each suffix has its own group, means completely sorted. */
			if(temp[len-1] == len-1)
				break;
			
			/* 
			Running time is with respect to the length of input String, len
			It is not neccessary that d grows larger than len, which will take O(log(len)). This will be the repreating number of outter for loop.
			Inside the loop, the main thing is sorting, which takes O(len*lon(len)). So the overall time is O(len*lon(len)*log(len)).

			*/	
		}
		
		int k = 0;
		for(int i = 0; i<len; i++, k = Math.max(k-1, 0))
		{
			/*
			Here we start from the longest suffix. i means a suffix array value.
			Note, After sorting suffix_arr, group[suffix_arr[i]] = i. 
			It is easy to see that the order of group and that of suffix_arr is the same.
			So, suffix_arr[group[i]+1] means the next suffix_arr in the ordered arr.
			Now we compare the two consecutive suffixes. 
			
			Here's another variable k. k denotes how many first letters are identical. For every iteration, k <= k-1 or 0.
			The reason is that as i is incremented by one, this means the first letter is deleted.

			For example, you compared ana, anana in the current iteration. This will give you lcp of 3.
			This means that the first 3 letters are the same. In the next iteration you will be comparing na with nana.
			From the previous iteration, we now that lcp of them is 2. This is why we're using k.
			ana
			anana
		
			na
			nana
			*/
			if(group[i] == len-1)
				continue;
			
			for(int j = suffix_arr[group[i]+1]; i+k < len && j+k < len && s[i+k]==s[j+k]; k++);
			LCP[group[i]] = k;
		}
			
		
		for(int i = 0; i<len; i++)
			System.out.print(suffix_arr[i] + 1 + " ");
		System.out.println();
		
		System.out.print("x ");
		for(int i = 0; i<len-1; i++)
			System.out.print(LCP[i] + " ");
		System.out.println();
		
		br.close();
	}
}