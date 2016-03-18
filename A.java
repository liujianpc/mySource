public class A
{
   static int age=23;
   static 
   {
      System.out.println("我今年"+age+"岁");
   }
   static void eat()
   {
      System.out.println("我要吃饭");
	  
   }
   public static void main(String[] args)
   {
       System.out.println(A.age);
   }
}
