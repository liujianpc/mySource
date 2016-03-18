import java.io.File;
public class FileCompare
{
	public static void main(String[] args)
	{
		File f1 = new File("c:/windows");
		File f2 = new File("c:/windows");
		if ((f1.compareTo(f2)) == 0)
		{
			System.out.println("duplicated file");
		}

		else
		{
			System.out.println("not duplicated!");
		}
	}
}