import java.util.*;

public class genericDemo
{

	public static < E > void printArray(E[] inputrray ) {
		
		for(E element:inputrray)
		{
			System.out.printf("%s",element);
		}
		System.out.println();
		
	}


	public static void main(String[] args ) {

		Integer[] intArray = {1,2,3,4};
		Double[] doubleArray = {1.0,2.0,3.0,4.0};
		Character[] charArray = {'a','b','c','d'};
		/*int[] intArray = {1,2,3,4};
		double[] doubleArray = {2.2,3.3,4.4,5.5};
		char[] charArray = {'d','f','g'};*/
		//System.out.println(intArray);
		//System.out.println(charArray);
		//System.out.println(doubleArray);
		printArray(intArray);
		printArray(doubleArray);
		printArray(charArray);		
		
	}
	
	
	
	
	

}