public class compareStringDemo
{
	/**
	 * method
	 *
	 * @param  
	 * @return 
	 */
	public static void main(String[] args ) {
		String str_1 = "Hello World!";
		String str_2 = "hello world!";
		System.out.println(str_1.compareTo(str_2));
		System.out.println(str_1.compareToIgnoreCase(str_2));
		System.out.println(str_1.compareTo(str_1.toString()))
		
	}
	
	
	
}