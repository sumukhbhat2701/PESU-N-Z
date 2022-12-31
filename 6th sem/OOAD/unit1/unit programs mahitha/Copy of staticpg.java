class demo {

    int a = 10;
    static int b = 23;

    void disp() {
        b++;
        a++;
        System.out.println("not static method");
        System.out.println("not static method" + b);
    }

    static void display() {
        // a++;
        System.out.println("static method");
    }

    static {
        System.out.println("ur in static block");
    }
}

class staticpg {
    public static void main(String args[]) {

        // demo.b=20;
        demo obj = new demo();
        demo obj1 = new demo();
        System.out.println("Value of static var b=" + demo.b);
        System.out.println("Value of non static var a=" + obj.a);
        obj1.a = 98;
        System.out.println("Value of non static var a=" + obj1.a);
        display();
        obj1.display();
        obj1.disp();
        demo.disp();
    }

    static {
        System.out.println("ur in static block2");
    }
}
