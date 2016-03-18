import java.io.IOException;
import java.io.PrintStream;
import java.net.*;
public class MutiThread implements Runnable
{
	Socket s;
	MutiThread(Socket s)
	{
		this.s = s;
	}

	public void run()
	{
		
	
		try
		{
			PrintStream print_str = new PrintStream(s.getOutputStream());
			
			for(int i = 0;i <= 100;i++)
			{
				print_str.println(i+"is my work!");
				
			}
			print_str.close();
			s.close();		
		}

		catch (IOException e)
		{
			System.out.println(e);
		}
		
		
	}

	public static void main(String[] args) throws Exception
	{
		ServerSocket socket_tmp = new ServerSocket(1234);
		System.out.println("It is a multiThread");
		while(true)
		{
		Socket socket_demo = socket_tmp.accept();
		MutiThread mut = new MutiThread(socket_demo);
		Thread thd = new Thread(mut);
		thd.start();
		}
		
		
	}
}