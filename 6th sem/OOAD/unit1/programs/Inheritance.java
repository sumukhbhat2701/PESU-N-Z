class A{
    A(){
        System.out.println("Ac");
    }
    static{
        System.out.println("As");
    }
    
}
class B extends A{
    B(){
        System.out.println("Bc");
    }
    static{
        System.out.println("Bs");
    }
    
}
class C extends B{
    C(){
        System.out.println("Cc");
    }
    static{
        System.out.println("Cs");
    }
    
}



public class Inheritance {
    public static void main(String[] args){
        B c= new C();
    }
}
