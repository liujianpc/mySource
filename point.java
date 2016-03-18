public class point
{ int x,y;
  void output()
	{ System.out.println(x);
	  System.out.println(y);
	}  
		public static void main(String[] args)
		{ point pt;
		  pt = new point();
		  pt.x=1;
		  pt.y=2;
		  pt.output();
		}

}