class dp
{
	public static void main(String[] args)
	{
		ProfileMaker p = new ProfileMaker();
		
		ProfileBuilder pb = (ResumeBuilder)p.buildProfile(1);
		String[] myPersonalInfo = {"Age = 20", "Name = Sumukh"};
		String[] myProfessionalInfo = {"Dept = CSE", "CGPA = 9.69"};
		Resume r = (Resume)pb.build(myPersonalInfo, myProfessionalInfo);
		r.print();
		
		ProfileBuilder pb1 = (PortfolioBuilder)p.buildProfile(2);
		String[] myBioData = {"I like XYZ", "Passionate in ABC"};
		String[] mysample = {"img1.jpg", "video1.mkv"};
		Portfolio po = (Portfolio)pb1.build(myBioData, mysample);
		po.print();

	}
}

class ProfileMaker
{
	public Object buildProfile(int n)
	{
		if(n == 1)
			return new ResumeBuilder();
		else
			return new PortfolioBuilder();
		
	}
}

class ProfileBuilder
{
	public Object build(String[] x, String[] y)
	{
		return "Main Profile Builder";
	}
}

class Resume
{
	static Resume r = new Resume();
	String[] personInfo;
	String[] professionalInfo;
	private Resume()
	{
	}
	
	public static Resume getInstance(String[] x, String[] y)
	{
		r.set(x, y);
		return r;
	}
	
	private void set(String[] x, String[] y)
	{
		personInfo = x;
		professionalInfo = y;
	}
	
	public void print()
	{
		System.out.println("Personal Info: ");
		for(int i = 0; i<personInfo.length; ++i)
			System.out.println(personInfo[i]);
		
		System.out.println("Professional Info: ");
		for(int i = 0; i<professionalInfo.length; ++i)
			System.out.println(professionalInfo[i]);
	}
	
}

class Portfolio
{
	static Portfolio p = new Portfolio();
	String[] bioData;
	String[] sample;
	private Portfolio()
	{
	}
	
	public static Portfolio getInstance(String[] x, String[] y)
	{
		p.set(x, y);
		return p;
	}
	
	private void set(String[] x, String[] y)
	{
		bioData = x;
		sample = y;
	}
	
	public void print()
	{
		System.out.println("BioData: ");
		for(int i = 0; i<bioData.length; ++i)
			System.out.println(bioData[i]);
			
		System.out.println("Sample: ");
		for(int i = 0; i<sample.length; ++i)
			System.out.println(sample[i]);
	}
}

class ResumeBuilder extends ProfileBuilder
{
	public Object build(String[] x, String[] y)
	{
		System.out.println("Building Resume...");
		return Resume.getInstance(x, y);
	}
}

class PortfolioBuilder extends ProfileBuilder
{
	public Object build(String[] x, String[] y)
	{
		System.out.println("Building Portfolio...");
		return Portfolio.getInstance(x, y);
	}
}



