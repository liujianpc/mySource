public class Stars{
public static void main(String[] args) {
  for (int j = 1; j <= 10; j++)
  {

   for (int z = 1; z <= 10 - j; z++)
   {
    System.out.print(" ");

   }
   for (int i = 1; i <= 2 * j - 1; i++)
   {
    System.out.print("*");
   } System.out.println();
  }

  for (int j = 1; j <= 10; j++)
  {
   for (int z = 1; z <= j; z++)
   {
    System.out.print(" ");
   }
   for (int i = 19 - j * 2; i >= 1; i--)
   {
    System.out.print("*");
   } System.out.println();
  }
 }
}
