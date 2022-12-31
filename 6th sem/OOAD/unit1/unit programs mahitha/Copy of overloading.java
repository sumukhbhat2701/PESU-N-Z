class rect
{
int l,b;

void add()
{
System.out.println("output= 0 ");
System.out.println("ur in zero arg method");
}
void add(int a)
{
System.out.println("output=  "+a);
System.out.println("ur in one arg method of type int");
}
void add(int a, int b)
{
System.out.println("output=  "+(a+b));
System.out.println("ur in two arg method of type int");
}
void add(int a, double b)
{
System.out.println("output=  "+(a+b));
System.out.println("ur in two arg method of type int,float");
}
void add(double a, int b)
{
System.out.println("output=  "+(a+b));
System.out.println("ur in two arg method of type float,int");
}
void add(double a, double b)
{
System.out.println("output=  "+(a+b));
System.out.println("ur in two arg method of type float,float");
}
}
public class demo
{
public static void main(String args[])
{
rect r=new rect(); 


r.add();
r.add(1,2);
r.add(1,2.4);
r.add(2.3,1);
r.add(1.1,3.5);
}}
