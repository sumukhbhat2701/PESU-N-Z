import java.util.*;
class Student{
    int no;
}
public class Array1 {
    public static void main(String[] args){
        int n;
        Student[] stu= new Student[10];

        System.out.println("Enter the array size within 10: ");
        Scanner in = new Scanner(System.in);
        n=in.nextInt();
        for(int i=0;i<n;i++){
            stu[i]=new Student();
        }
        for(int i=0;i<n;i++){
            stu[i].no=in.nextInt();
            System.out.println("========");
        }
        for(int i=0;i<n;i++){
            System.out.println(stu[i].no);
        }
        in.close();
    }
}
