class removeChar 
{
	public static void main(String[] args) 
	{
		String str = "hello,world!"
		System.out.println(remove(str,3));
		System.out.println(new StringBuffer(str).reverse().toString());
		System.out.println(str.toUpperCase());
	}


	public static String remove(String s, int position ) {
		return s.substring(0,position) + s.substring(position+1);
		
	}
	
	
}
