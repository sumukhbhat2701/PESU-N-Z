class A{
    void f(){System.out.println("Hi");}
    int f(int x){System.out.println("Hello");return x;}

}


public class Overloading {
    
    public static void main(String[] args){
        A s=new A();
        s.f();
        s.f(10);

    }
}
