class A
{
//base class, parent class, super class
int i;
int j;
static int p=100;
void showij()
{
System.out.println("i and j"+" "+i+" "+j );
}

}

class B extends A
{
//child class, sub class, derived class

int k;

void showk()
{
//showij();
//System.out.println("i and j"+" "+i+" "+j );
System.out.println("k="+" "+k);
}

void sum()
{
//System.out.println("i+j+k"+" "+(j+k));

}
}
class C extends A //hierarchical inhert
{
int x;
void display()
{
System.out.println("in class C");
System.out.println("with x="+" "+x);
}
}

class inheritpg
{
public static void main(String args[])
{

A pobj=new A();
B cobj=new B();
C scobj=new C();
System.out.println("Static P"+ " " +A.p);//100
System.out.println("Static P"+ " " +B.p);//100
//B.p=200;//200, child class is changing val of static dm
cobj.p=300;//300
System.out.println("Static P"+ " " +A.p);
System.out.println("Static P"+ " " +B.p);
System.out.println("Static P"+ " " +cobj.p);
System.out.println("Static P"+ " " +pobj.p);
System.out.println("sub class obj contents");
scobj.x=10000;

scobj.i=11;
scobj.j=12;
//scobj.k=13;
scobj.showij();
//scobj.showk();
scobj.display();



//pobj.i=10;// i is a private DM
pobj.j=20;
//pobj.k=1000;
System.out.println("Parent obj infor");
pobj.showij();

//cobj.i=100;// is private to class A
cobj.j=200;
cobj.k=300;
System.out.println("Child obj infor");
cobj.showij();
cobj.showk();
cobj.sum();
}
}