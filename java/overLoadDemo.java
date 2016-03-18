public class overLoadDemo
{
	static void overLoadTest(int ... no)
	{
		for(int n : no)
		{
			System.out.printf(n+" ");
			
		}
		System.out.println();
	}

	static void overLoadTest(char ... no)
	{
		for(char c : no)
		{
			System.out.print(c+" ");
		}
			System.out.println();
	}

	static void overLoadTest(String ... arg)
	{
		for(String str : arg)
		{
			System.out.print(str+" ");
		}
		System.out.println();
	}

	static void overLoadTest(String no,char ... chartest)
	{
		for(char c : chartest)
		{
			System.out.print(c+" ");
		}
		System.out.println();
	}

	public static void main(String[] args)
	{
		overLoadTest(1,2,3,4);
		overLoadTest("a","b","c","d");
		overLoadTest("liujian","is","hansome","man");
		overLoadTest("jjj",'c','d','f');
	}
}