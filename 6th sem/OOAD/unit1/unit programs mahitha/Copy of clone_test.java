// covariant return type
class Rectangle implements Cloneable{
	private int length,breadth;
	Rectangle(int l, int b)
	{
		length = l;
		breadth = b;
	}
	// clone is protected in Object class
	public Rectangle clone()   // covariant return type
	{
		Rectangle r = null;;
		try
		{
				r= (Rectangle)super.clone();
		}
		catch(CloneNotSupportedException e)
		{
				System.out.println("error"+e);
		}
		return r;
	}
	void setLength(int l)
	{
			length = l;
	}
	public String toString()
	{
		return length +" "+breadth;
	}
	
	
}
class clone_test
{
	public static void main(String[] args)
	{
		Rectangle r1 = new Rectangle(3,4);
		Rectangle r2 = r1;   // wherver r1 is pointing, r2 is also pointing at the same object/location
		Rectangle r3 = r1.clone();
System.out.println(r1.hashCode());
System.out.println(r2.hashCode());
System.out.println(r3.hashCode());
		System.out.println(r1);
		System.out.println(r2);
		System.out.println(r3);
		r1.setLength(300);//lenght of r1 is updated-->r2
System.out.println("equals= "+r1.equals(r2));
System.out.println("equals= "+r1.equals(r3));
System.out.println("equals= "+r2.equals(r3));

		System.out.println(r1);
		System.out.println(r2);
		System.out.println(r3); //new so no updated
		
		
	}
}