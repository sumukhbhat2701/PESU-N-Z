	class Test
	{	int x;		
		
		Test(int i) 
		{ x = i; }; 	
		
		Test()   
		{ x = 0; }
	}	  
	class Main2
	{
		public static void main(String[] args)
		{	Test t = new Test(5);
			System.out.println(t.x);//5
	
		change(t);

			System.out.println(t.x); //10
// new value of x is printed here
			// it is 10
		}
		public static void change(Test a)
		{	 a.x = 10;
    
               }
	}
	
	
	
	
	
	
	
	// This change() doesn't change the reference, it only
   // changes member of object referred by reference	