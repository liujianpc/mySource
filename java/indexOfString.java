class indexOfString
{
	public static void main(String[] args) 
	{
		String str = "hello word,hello jingle";
		if (-1 != str.lastIndexOf("hello")) {
			System.out.println(str.lastIndexOf("hello"));
		}
		else System.out.println("not found");
	}
}
