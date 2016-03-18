public class Me
{
   String dream;
   void M(String s)
   {
     dream=s;
	 System.out.println("我的梦想是"+dream);
	 
   }
   public static void main(String[] args)
   {
      Me m=new Me();
	  m.M("买房买车");
   }
}
