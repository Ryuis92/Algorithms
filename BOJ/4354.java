/* https://www.acmicpc.net/problem/4354 */
/*KMP version
ref: https://mygumi.tistory.com/61
	 https://bowbowbow.tistory.com/6
	 http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220710595298&parentCategoryNo=&categoryNo=304&viewDate=&isShowPopularPosts=false&from=postView
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] s = br.readLine().toCharArray();
		while(s[0] != '.')
		{
			int len = s.length;
			int[] fail = new int[len];
			fail[0] = 0;
			
			/* Making failure arr of KMP algorithm */
			int j = 0;
			for(int i =1; i<len; i++)
			{
				/* shift j according to the failure function */
				while(j > 0 && s[i] != s[j])
					j = fail[j-1];
				
				if(s[i] == s[j])
					fail[i] = ++j;
				/* when j == 0 */
				else 
					fail[i] = 0; 
			}
			int last = fail[len-1];
			
			/*
			if last = 0, then len - last = len. This means no repeating substring in the input string.
			if len % (len - last) = 0, this means that last is equal to the half of len at least or greater than that.
			This is an important property to note. last should be at least len/2, or it will not work.

			For example let's think about this input, aabbbbaa. last of it is 2. len is 8.
			Now we can split it into 3 parts: aa-bbbb-aa. You can see that first and last part is the same, but not the middle part.
			It can also be put another way. the value of last means the length of the longest possible repeatible component, or substring.
			Likewise len - last means the length of shortest possible repeatible substring. From this observation, last >= len - last, which results in last >= len/2
			
			For detailed explanation, refer to http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220710595298&parentCategoryNo=&categoryNo=304&viewDate=&isShowPopularPosts=false&from=postView.
			 */
			if(len %(len-last) == 0)
				System.out.println(len /(len-last));
			else
				System.out.println(1);
			
			s = br.readLine().toCharArray();
		}
		
		br.close();
	}
}

/*
Bruceforce version

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] s = br.readLine().toCharArray();
		while(s[0] != '.')
		{
			int len = s.length;
			int ans = 1;
			boolean flag = false;
			for(int i = 1; i<=len; i++)
			{
				if(len % i == 0)
				{
					for(int j = 0; j<len; j += i)
					{	
						flag = false;
						for(int k = 0; k<i; k++)
						{
							if(s[k] != s[k+j])
							{
								flag = true;
								break;
							}
						}
						
						if(flag)
							break;
					}
					
					if(!flag)
					{
						System.out.println(len/i);
						break;
					}
				}
			}
			s = br.readLine().toCharArray();
		}
		
		br.close();
	}
}
 */