// A factory method is a method that returns the instance of the class. We will learn about the factory method later.



abstract class Vehicle{
    abstract void tyres();
}
class Car extends Vehicle{
    void tyres(){
        System.out.println("Car has 4 tyres");
    }
}
class Bus extends Vehicle{
    void tyres(){
        System.out.println("Car has 6 tyres");
    }
}
public class AbstractClass2 {
    public static void main(String[] args){
        Vehicle c=new Car();
        c.tyres();
        Vehicle b=new Bus();
        b.tyres();
    }
}
