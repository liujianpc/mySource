public class TestUtil
{
	public static double EvenNum2(double num1,double num2) {
		double s = 0;
		int[] j = new int[6];
		for(int i = 0, w = 0;i < 20; i++)
		{
			j[w] = (int)num1 + (int)(Math.random()*(num2-num1));
			if (j[w] != 0 && j[w] % 2 == 0) {
				System.out.println("print"+j[w]);
				s += j[w];
				w++;
				// expression
			}
			if(w == 6) break;
		}
		return s;
	}

	public static void main(String[] args) {
		System.out.println("sum is:"+EvenNum2(2,32));
	}
}