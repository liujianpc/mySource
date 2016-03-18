import java.util.BitSet;
public class BitSetDemo
{
	public static void main(String[] args) 
	{
		BitSet bit1 = new BitSet();
		BitSet bit2 = new BitSet();
		int i = 0;
		while (i < 16) {
			if (i%2 == 0) {
				bit1.set(i);
				// expression
			}
			if (i%5 != 0) {
				bit2.set(i);					
			}	
			i++;
		}
		System.out.println("bit1:"+bit1);
		System.out.println("bit2:"+bit2);
		bit1.clear();
		System.out.println("bit1(1)"+bit1);
		
	}
}
