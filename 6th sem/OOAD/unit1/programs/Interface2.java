// Multiple inheritance in Java by interface
// If a class implements multiple interfaces, or an interface extends multiple interfaces, it is known as multiple inheritance.



interface A{
    void a();
}
interface B{
    void b();
}
class C implements A,B{
    public void a(){System.out.println("A");}
    public void b(){System.out.println("B");}

}

public class Interface2 {
    public static void main(String[] args){
    C q=new C();
    q.a();
    q.b();
    }
}
