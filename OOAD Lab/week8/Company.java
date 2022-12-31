// SRN: PES1UG19CS519
import java.util.Scanner;

public class Company{
    public static void main(String[] args)
     {

        Scanner sc = new Scanner(System.in);
        int level;
        System.out.println("SRN: PES1UG19CS519");
        System.out.println("Enter the task level for the task:");
        level = sc.nextInt();
        sc.close();
        Task task = new Task("Tester", "High", "Started", level, "Easy", "1 day");
         Employee techLead = new TechLead();
        Employee developer = new Developer();
         Employee manager = new Manager();
         
         if(task.taskLevel==1)
        {
          task.openedBy(techLead);
          task.executedBy(developer);
        }
        else if(task.taskLevel==2)
        {
          task.openedBy(manager);
          task.executedBy(techLead);
        }
        else if(task.taskLevel==3)
        {
          task.openedBy(manager);
          task.executedBy(manager);
        }
        else
        {
          System.out.println(level + " not recognized as a valid level. Valid levels are 1, 2 and 3.");
        }
      }
}














