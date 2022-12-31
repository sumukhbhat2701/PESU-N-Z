interface writeableobj
{
 void write();//public and abstract
//can i have data members?-->yes u can 
int c=10; //static and final, class scope
}
interface readableobj
{
void read();
}
class demo
{
//some definition

}
class pen extends demo implements writeableobj,readableobj
{
public void write()
{
System.out.println("I am a pen");
}
public void read()
{
c++;
System.out.println("ur reading");

}
}

class pencil extends demo implements writeableobj
{
public void write()
{
System.out.println("I am a pencil");
}
}

class kit
{
void dosomething(writeableobj p)
{
p.write();
}

}

class intfer
{
public static void main(String args[])
{
kit k=new kit();
pen p=new pen();
pencil pc=new pencil();
k.dosomething(p);
k.dosomething(pc);
}
}
