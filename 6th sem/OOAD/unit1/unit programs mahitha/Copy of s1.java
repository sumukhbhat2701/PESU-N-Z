class child    ///output???
{
	private final void flip()
	{
		System.out.println("hello");
	}
void disp()
{
flip();
}
}

public class s1 extends child
{
	public final void flip()
	{
		System.out.println("hi");
	}
	public static void main(String[] args)
	{
		new s1().flip();
	}
}
