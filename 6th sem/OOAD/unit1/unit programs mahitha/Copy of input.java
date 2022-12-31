/*read input from the input stream
Scanner sc1 = new Scanner(InputStream input);

// read input from files
Scanner sc2 = new Scanner(File file);

// read input from a string
Scanner sc3 = new Scanner(String str);
*/

//Scanner s = new Scanner(System.in);

import java.util.Scanner;

class input
{
public static void main(String args[])
{
Scanner s=new Scanner(System.in);
int x;
float y;
double z;
char c;
String st;
boolean b;


System.out.println("enter an integer ");
x=s.nextInt();


System.out.println(x);
System.out.println("enter an float");
y=s.nextFloat();

System.out.println(y);
System.out.println("enter an double");
z=s.nextDouble();

System.out.println(z);
System.out.println("enter a boolean");
b=s.nextBoolean();

System.out.println(b);
s.nextLine();
System.out.println("enter a string");
st=s.nextLine();
System.out.println(st);
System.out.println("enter a char");
c = s.next().charAt(0);   
System.out.println(c);
}
}