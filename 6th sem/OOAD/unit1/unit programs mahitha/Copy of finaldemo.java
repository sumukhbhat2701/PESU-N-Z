class finaldemo
{
public static void main(String args[])
{

demo d = new demo();
demo d1 = new demo();
//d.a++;
d.b++;
System.out.println("d.a = "+d.a);
System.out.println("d.b = "+d.b);
System.out.println("d1.a = "+d1.a);
System.out.println("d1.b = "+d1.b);
deriveddemo d2=new deriveddemo();
d.show();//hello
d2.show();//good morning-->hello
d.disp();//hru
d2.disp();//hru from cc
}
}

final class demo
{
final int a=1000;
int b=100;
final void show()
{
System.out.println("hello");
}
void disp()
{
System.out.println("hru");
}
}

class deriveddemo extends demo
{
void disp()
{
System.out.println("hru from cc");
}
}

