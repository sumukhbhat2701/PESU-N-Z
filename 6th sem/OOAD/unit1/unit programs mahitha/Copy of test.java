class A {
    A() {
        System.out.println("A");
    }
}

class B extends A {
    int i;

    B(int j) {
        i = j;
        System.out.println("B");
    }
}

class C extends B {
    int k;

    C(int n) {

        super(n);
        i = 30;
        System.out.println("C");
        System.out.println("val of i,k=" + " " + i + " " + k);
    }
}

class test {
    public static void main(String args[]) {

        C obj = new C(10);
    }
}
