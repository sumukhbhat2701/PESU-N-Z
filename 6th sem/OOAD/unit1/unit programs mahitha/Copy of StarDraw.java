//StarDraw.java
public class StarDraw 
{

     void drawStar(int n) {
        if (n == 1) 
{
            System.out.println("*");
        } 
else {
            System.out.print("*");
            drawStar(n - 1);
        }
    }

    public static void main(String[] args) {
StarDraw obj=new StarDraw();
        obj.drawStar(5);
        obj.drawStar(4);
        obj.drawStar(3);
        obj.drawStar(2);
        obj.drawStar(1);
    }
}
