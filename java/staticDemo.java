class staticDemo
{
	static int a = 1;
	public int getA()
	{
		return staticDemo.a;//ªÚ’ﬂreturn a; return this.a
	}
	public static void main(String[] args) 
	{
		staticDemo sta = new staticDemo();
		System.out.println(sta.getA());
	}
}
