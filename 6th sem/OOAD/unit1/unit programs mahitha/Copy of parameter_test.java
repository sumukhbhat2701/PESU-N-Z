class parameter_test
{
	public static void main(String[] args)
	{	int data = 7;
		parameter p1 = new parameter();
		System.out.println(data);//7
		p1.testing(data);
		System.out.println(data);//
	}
}
class parameter{	
	void testing(int data)
	{		data = 89;	}
}