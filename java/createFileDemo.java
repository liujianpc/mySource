import java.io.File;
import java.io.IOException;
import java.util.Date;

public class createFileDemo
{
	public static void main(String[] args) throws Exception
	{
		try
		{
			File f = new File("d:/new.txt");
			if (f.createNewFile()) {
				System.out.println("�ļ������ɹ���");
			}

			else
			{
				System.out.println("�ļ��Ѿ����ڣ����轨����");
			}
		}

		catch(IOException e)
		{
			e.printStackTrace();
		}

		File f1 = new File("d:/new.txt");

		Long lastModifiedTime = f1.lastModified();
		Date d = new Date(lastModifiedTime);
		System.out.println(d);

		File f2 = null;
		File dir = new File("d:/");
		f2 = File.createTempFile("ddd","eee",dir);
		System.out.println(f2.getPath());
		
	}
}