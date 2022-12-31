public class RecursiveSum 
{
    static int RSum(int num) 
{
        if (num == 0) 
	{
            return 0;
        } 
else {
            return num % 10 + RSum(num / 10);
        }
    }

    public static void main(String[] args) {

        int n = 123456789;
        int rResult = RSum(n);
        System.out.println("Recursive result=" + rResult);
      }
}

