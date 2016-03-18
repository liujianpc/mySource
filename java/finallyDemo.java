public class finallyDemo
{
	public static void main(String[] args)
	{
		new finallyDemo().doWork();
		
	}

	public void doWork()
	{
		Object o = null;
		for(int i = 1;i < 5;i++)
		{
			try
			{
				o = makeObj(i);
				
			}
			catch(IllegalArgumentException e)
			{
				System.out.println("Error:"+e.getMessage());
			}

			finally
			{
				System.err.println("All finished!");
				if (o == null)
				{
					System.exit(0);
					
				}
			}
			System.out.println(o);
		}
	}

	public Object makeObj(int type) throws IllegalArgumentException
	{
		if (type == 1) {
			throw new IllegalArgumentException("it is error"+type);
		}
		return new Object();
	}
}