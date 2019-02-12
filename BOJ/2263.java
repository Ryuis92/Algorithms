import java.util.Scanner;

public class Main 
{	
	int[] preorder = null;
	int[] inorder;
	int[] postorder;
	int pre_index = 0;
	public void solve() 
	{
		Scanner sc = new Scanner(System.in);
		
		int num;
		
		String[] temp;
		
		num = sc.nextInt();
		this.inorder = new int[num];
		this.postorder = new int[num];
		this.preorder = new int[num];
		sc.nextLine();
		
		temp = sc.nextLine().split(" ");
		for(int i = 0; i < num ; i++)
		{
			inorder[i] = Integer.parseInt(temp[i]);
			//this.preorder[i] = inorder[i];
		}
		temp = sc.nextLine().split(" ");
		for(int i = 0; i < num ; i++)
			postorder[i] = Integer.parseInt(temp[i]);
		
		getPre(0, num-1, 0, num-1);
		
		for(int i = 0; i < num ; i++)
			System.out.print(this.preorder[i] + " ");
	}
	
	public void getPre(int is, int ie, int ps, int pe)
	{
		if(is > ie || ps > pe)
			return;
		
		int root = this.postorder[pe];
		this.preorder[this.pre_index++] = root;
		
		
		int i = is;
		for (; i <ie; i++)
			if(this.inorder[i] == root)
				break;
		
		getPre(is, i-1, ps, ps + i-is-1);
		getPre(i+1, ie, ps + i-is,pe-1);
	}
	
	public static void main(String[] args) 
	{
		Main m = new Main();
		m.solve();
	}
}