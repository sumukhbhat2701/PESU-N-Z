class TEST
{
	public static void main(String[] args)
	{
		
		/*System.out.println(args[0]+" "+args[1]+" "+args[2]);
		main();
		main(2,3);
		A b = new A();
		System.out.println(b.a); 
		
		A a = new A();
		System.out.println(A.x);
		//A.x++;
		A b = new A();
		System.out.println(A.x);
		//A.f();
		a.g();
		a.g(5);*/
		
		//C c = new C(2,3);
		
		B b = new C(); // upcast
		
		b.f(); // overriden - of child class!
		
		C c = (C)b; // downcast
		
		double x = 2;  // upcasting
		int y = (int)2.3;   // downcasting - (int) compulsory, otherwise error - looses precision
		
		X t = new X();
		t.f();
		
		char d = 'a';
		System.out.println(d % 2 == 0);
		
		G<Integer> j = new G<>(2);
		
		
		A l = new A();
		
		A l2 = new A();
		
		System.out.println(l);
		
		B f = new C();
		f.g();
		
		System.out.println("--------------");

		//System.out.println(q.x);
		
		long m = 5L;
		int n = (int)m;
		k w = new k();
		
		
		
		
		
		
		
	}
	
	public static void main()  // main can be overloaded and called inside any class
	{
		
		System.out.println("0 params");
	}
	
	
	
	public static void main(int x, int y)   
	{
		
		System.out.println("2 param");
	}
}


class k
{
	public k(int a) {}
	public k() {}
}
/*
class Base
{
	public int x;
	public Base(int a) { x = a; }
	public void f() { System.out.println("Hello" ); };
}

class Child extends Base
{
	public int x;

	public void f() { System.out.println("World" ); };
}

*/

class Student18 implements Cloneable{   // Cloneable interface
	int rollno;  
	String name;  
  
	Student18(int rollno,String name){  
		this.rollno=rollno;  
		this.name=name;  
	}  
  
  	// functions in Object:
	public Object clone()throws CloneNotSupportedException{ // make public  
		return super.clone();  // super.clone()
	}
	
	// executes when System.gc(); is called in client
	protected void finalize()
	{
	}
	
	public String toString()
	{
		return name;
	}
	
	public boolean equals(Object x) // Object not Student18
	{
		Student18 y = (Student18)x;
		return y.rollno == rollno;
	}
}  

class B
{
	public B()
	{
	}
	
	
	public Object f()
	{
		System.out.println("In B.f()");
		return null;
	}
	
	public void g()
	{
		System.out.println("A");
	}
	
}
// inherits both static members and functions of B, but cant override static functions
// @override just for readibilty and compiler does a check if its actually overrided. Even works without it. Just for compile time safety.
// overriding - ditto function prototype, even returntype
class C extends B
{
	public C()
	{
	}
	

	// covariant return type
	public String f()
	{
		System.out.println("In C.f()");
		return "Hello world";

	}
	
	
	
	/*public C(int x, int y)
	{
		f();
	}
	
	private void f()
	{
		System.out.println("Hey man - 2");
		g();
	}
	
	public static void g()
	{
		//f();
	}*/
	
	public void g()
	{
		System.out.println("B");
	}
		
}

interface I
{
	// final => has to be initialized
	int a = 10;
	void f();
}

class X implements I
{
	public void f()
	{
		System.out.println("In I.X.f():"+a);
	}
}

interface U
{
}

interface V
{
}

class Y implements U, V
{
}

class A
{
	static int x;  // init to 0 (unlike c++ where init is compulsory)
	int y;
	A()
	{	//y= 0;
		System.out.println("Ctor man");
	}
	
	public static void f()  // static functions can only access static members
	{
		//System.out.println(x+" "+y);
		System.out.println("static f");
	}
	
	public void g()  // non static functions can access both 
	{
		System.out.println(x+" "+y);
	}
	
	public int g(int t)
	{
		System.out.println(t+" man");
		return t*10;
	}
	
	// only once for n-objects, before ctor
	
	{ System.out.println("Sup man1");}
	
	{ System.out.println("Sup man2");}
	
	static
	{  System.out.println("Hey man1");}
	
	static
	{  System.out.println("Hey man2");}
	
	
	
}

class G<T>
{
	G(T x)
	{
		System.out.println(x);
	}
}
