import java.lang.*;
public class atomNo
{
	public static void main(String[] args)
	{
		for(int i = 101;i <= 200;i++)
		{
			int flag = 0;
			for(int j = 2; j <= Math.sqrt(i);j++)
			{
				if (i%j == 0)
				{
					flag = 1;
					break;
				}
			}
			if(flag == 1)
			{
				System.out.println(i);
			}
		}

	}
}