class Test
{
    int x;
    Test(int i) { x = i; }
    Test()      { x = 0; }
}
  
class Main3
{
    public static void main(String[] args)
    {
        
        Test t = new Test(5);
  
        
	System.out.println(t.x); 
        change(t);
  
       
        System.out.println(t.x);  
    }
  
   
    public static void change(Test a)
    {
		a = new Test();
        a.x = 10;
    }
}



// this changes the reference and thus the member of the object