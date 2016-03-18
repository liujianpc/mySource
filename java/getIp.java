import java.net.*;
public class getIp
{
	public static void main(String[] args)
	{
		 InetAddress addr = null;
		try
		{
			addr = InetAddress.getByName("www.baidu.com");
		}
		catch(Exception e)
		{
			System.err.println(e);
		}

		finally
		{
			System.out.println(addr.getHostName() + "==" + addr.getHostAddress());
			System.exit(0);
		}
	}
}