// The abstract class can also be used to provide some implementation of the interface. In such case, the end user may not be forced to override all the methods of the interface.

interface A{
    void a();
}
class B implements A{
    public void a(){
        System.out.println("B");
    }
}
public class Interfacepro1 {
    public static void main(String[] args){
        A a=new B();
        a.a();
    }
}
