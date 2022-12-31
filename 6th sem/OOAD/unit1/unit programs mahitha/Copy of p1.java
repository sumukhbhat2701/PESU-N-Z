import java.util.Scanner;

public class p1
{
	public static void main(String args[])
	{
		int [] a = new int[100];
		int n,x;
		int count=0;
		System.out.println("enter the size of array");
		Scanner s =new Scanner(System.in);
		n=s.nextInt();
		
		
		System.out.println("enter"+n+ "numbers");
		
		for(int i=0;i<n;i++)
		a[i]=s.nextInt();
		
		System.out.println("Enter the number to be counted for no of occurences");
		x=s.nextInt();
			for(int i=0;i<n;i++)
				{
				  if(a[i]==x)
					count++;
				  else
					continue;
				}
		System.out.println("Number of occurences of "+ x +" is "+count);


}
}