import java.text.SimpleDateFormat;
import java.util.Date;
public class timeDemo
{
	public static void main(String[] args)
	{
		Date currentTime = new Date();
		String format = "yyyy--MM--dd--HH:mm:ss";
		SimpleDateFormat pattern = new SimpleDateFormat(format);
		System.out.println(pattern.format(currentTime));		
		 
	}
}