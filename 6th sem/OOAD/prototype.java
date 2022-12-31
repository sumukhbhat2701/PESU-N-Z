class prototype
{
	public static void main(String[] args)
	{
		Prototype p = new Prototype();
		Shape c = p.clone(2);
		Shape r = p.clone(1);
		System.out.println(c.area());
		System.out.println(r.area());
		
	}
}

interface Shape
{
	double area();
}

class Rectangle implements Shape
{
	int l, b;
	Rectangle(int x, int y)
	{
		l = x;
		b = y;
	}
	public double area()
	{
		return l*b;
	}
}

class Circle implements Shape
{
	int r;
	Circle(int x)
	{
		r = x;
	}
	public double area()
	{
		return 3.142*r*r;
	}
}

class Prototype
{
	Rectangle R;
	Circle C;
	Prototype()
	{
		R = new Rectangle(10, 20);
		C = new Circle(50);
	}
	Shape clone(int x)
	{
		if(x == 1)
			return R;
		else 
			return C;
	}
}


