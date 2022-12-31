class A
{
void show()
{
System.out.println("I am in class A");
}
}

class B extends A
{
void show()
{
System.out.println("I am in class B");
//super.show();
}
}

class override
{
public static void main(String args[])
{
A pobj=new A();
B cobj=new B();
A ref;
ref=cobj;
ref.show();






//pobj.show();//Base class show method is called
//cobj.show();//Derived class show method is called

}
}
