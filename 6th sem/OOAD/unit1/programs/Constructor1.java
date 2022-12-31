import java.util.*;

class Student{
    String srn;
    String name;
    Student(){                  //Constructor
        srn="PES1UG19CS444";
        name="Shamanth";
    }
    Student(String s,String n){
        srn=s;
        name=n;
    }
    void display(){
        System.out.println(srn);
        System.out.println(name);
    }
}

class Constructor1{
    public static void main(String[] args){
        Student st1=new Student();
        Student st2=new Student("PES1UG19CSxxx","XYZ");
        st1.display();
        System.out.println("------------------------");
        st2.display();

    }
}