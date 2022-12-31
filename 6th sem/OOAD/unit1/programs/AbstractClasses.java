// Abstract class in Java
// A class which is declared with the abstract keyword is known as an abstract class in Java.
// It can have abstract and non-abstract methods (method with the body).

// Abstraction is a process of hiding the implementation details and showing only functionality to the user.

// There are two ways to achieve abstraction in java
// 1. Abstract class (0 to 100%)
// 2. Interface (100%)



abstract class Base {
    abstract void fun();
}
// Class 2
class Derived extends Base {
    void fun()
    {
        System.out.println("Derived fun() called");
    }
}
public class AbstractClasses {
    public static void main(String args[])
    {

        // Uncommenting the following line will cause
        // compiler error as the line tries to create an
        // instance of abstract class. Base b = new Base();

        // We can have references of Base type.
        Base b = new Derived();
        b.fun();
    }
}
