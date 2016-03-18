import java.util.*;
public class testArray
{
	public static void main(String[] args)
	{
		int[] intArray = new int[]{9,7,8,4,5,3};
		Arrays.sort(intArray);
		for(int i = 0;i<intArray.length;i++)
		{
			System.out.println(intArray[i]);
		}
		
	}
}