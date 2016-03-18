public class threeFive
{
	public static void main(String[] args)
	{
		int count = 0;
		for(int i = 1;i <= 100 ; i++)
		{
			if (count == 3)
				break;
			if (i % 5 == 0)
			{
				count++;
				System.out.println(i);
			}
		}
	}
}