public class Exception_Demo
{
	int[]  arr = new int[3];
	
	Exception_Demo(int[] a)
	{
		arr = a;
	}

	public static void main(String[] args)
	{
		Exception_Demo Except = new Exception_Demo(new int[]{1,2,3});
		try
		{
			
			
			System.out.println(Except.arr[4]);
			
			
		}

	
		catch(ArrayIndexOutOfBoundsException e2)
		{
			System.out.println("outofbounds");
			try{
				System.out.println(Except.arr[1]/0);
			}
			catch(ArithmeticException e1)
			{
				System.out.println("div-error!");
				try{
					Exception_Demo Except1 = null;
					System.out.println(Except1.toString());
				}
				catch(NullPointerException e3)
				{
					System.out.println("null pointer");
				}

			}
		}
		
	}
}