 public class Javatest2{
    public static void main(String[] args){
        final String pig = "length: 10";
		int a=pig.length();
		final String dog = "length: " + a;
       System.out.println(pig == dog);
	   System.out.println(dog);
	   System.out.println(pig);
    }
}