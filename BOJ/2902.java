/* https://www.acmicpc.net/problem/2902 */
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String[] token = sc.nextLine().split("-");
		
		for(int i =0; i<token.length; i++)
			System.out.print(token[i].charAt(0));
		System.out.println();
			
	}
}