import java.lang.*;
public class Point
{
	double x,y,z;
	Point(double a,double b,double c)
	{
		x = a;
		y = b;
		z = c;
	}
	void setPoint(double a,double b,double c)
	{
		this.x = a;
		this.y = b;
		this.z = c;
	}

	double distance()
	{
		return Math.sqrt(x*x+y*y+z*z);
	}

	public static void main(String[] args)
	{
		Point p = new Point(1,2,3);
		System.out.println(p.distance());
		p.setPoint(2,3,4);
		System.out.println(p.distance());
	}
}