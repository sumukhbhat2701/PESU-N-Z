interface Shape
{
	public void draw();
}

class Circle implements Shape
{
	public void draw()
	{
		System.out.println("Drawing circle");
	}
}

class Square implements Shape
{
	public void draw()
	{
		System.out.println("Drawing Square");
	}
}

class Rectangle implements Shape
{
	public void draw()
	{
		System.out.println("Drawing Rectangle");
	}
}

class ShapeFactory
{
	public Shape build(int n)
	{
		if(n == 1)
			return new Circle();
		else if(n == 2)
			return new Rectangle();
		else
			return new Square();
	}
}

class shapeFactory
{
	public static void main(String[] args)
	{
		ShapeFactory sf = new ShapeFactory();
		
		Shape s1 = sf.build(1);
		s1.draw();
		
		Shape s2 = sf.build(2);
		s2.draw();
		
		Shape s3 = sf.build(3);
		s3.draw();
	}
}
