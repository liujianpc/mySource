/*
 author by w3cschool.cc
 Main.java
 */

import java.net.*;
import java.io.*;

public class Main {
   public static void main(String[] args) {
      Socket Skt;
      String host = "localhost";
      if (args.length > 0) {
         host = args[0];
      }
      for (int i = 0; i < 1024; i++) {
         try {
            System.out.println("�鿴 "+ i);
            Skt = new Socket(host, i);
            System.out.println("�˿� " + i + " �ѱ�ʹ��");
         }
         catch (UnknownHostException e) {
            System.out.println("Exception occured"+ e);
            break;
         }
         catch (IOException e) {
         }
      }
   }
}