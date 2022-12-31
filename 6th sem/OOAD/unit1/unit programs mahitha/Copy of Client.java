import java.util.*;
public class Client
{
public static void main(String[] args)
{
Scanner scanner = new Scanner(System.in);
System.out.println("Enter the number");
int n = scanner.nextInt();
MyNum mynum1 = new MyNum(n);
int sum = mynum1.findSum();
System.out.println("sum : " + sum);
scanner.close();
}
}   