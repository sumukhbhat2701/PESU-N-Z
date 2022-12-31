class A {
    void show() {
        System.out.println("show of class A");
    }
}

class B extends A {

    void show() {
        System.out.println("show of class B");
    }

    void disp() {
        System.out.println("show of class B disp");
    }
}

class supertest {
    public static void main(String[] args) {
        A aobj = new A();
        B bobj = new B();
        A ref;
        ref = aobj;
        ref.show();// show of class A will
        ref = bobj;
        ref.show();// show of class A/Class B????
        // ref.disp();
    }
}