public class Star{
 public static void main(String[] args){
  int i,j,k;
  for(i = 1;i<=7;i++){
   for(j = 0; j <= 7 - i; j++){
    System.out.print(" ");
   }
   for(k = 0; k <= i - 1; k++){
    System.out.print("* ");
   }
   System.out.println();
  }
  for(i = 6; i > 0; i--){
   for(j = 0; j <= 7 - i; j++){
    System.out.print(" ");
   }
   for(k = 0; k <= i - 1; k++){
    System.out.print("* ");
   }
   System.out.println();
  }
 }
}