/*
 author by runoob.com
 Main.java
 */

import java.net.URL;
import java.net.URLConnection;

public class getRemoteFile {
   public static void main(String[] argv) 
   throws Exception {
      int size;
      URL url = new URL("http://www.w3cschool.cc/wp-content/themes/w3cschool.cc/assets/img/newlogo.png");
      URLConnection conn = url.openConnection();
      size = conn.getContentLength();
      if (size < 0)
      System.out.println("�޷���ȡ�ļ���С��");
      else
      System.out.println("�ļ���СΪ��" +
      + size + " bytes");
      conn.getInputStream().close();
   }
}