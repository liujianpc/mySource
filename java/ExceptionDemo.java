/*
 author by w3cschool.cc
 ExceptionDemo.java
 */

class Demo  
{  
    int div(int a,int b) throws ArithmeticException,ArrayIndexOutOfBoundsException//�ڹ�����ͨ��throws�Ĺؼ��������ù��ܿ��ܳ�������  
    {  
        int []arr = new int [a];  
  
        System.out.println(arr[4]);//����ĵ�һ���쳣  
  
        return a/b;//����ĵڶ����쳣  
    }  
}  
  
  
class ExceptionDemo  
{  
    public static void main(String[]args) //throws Exception  
    {  
        Demo d = new Demo();  
  
        try  
            {  
                int x = d.div(4,0);//�������н�ͼ�е�����ʾ�� �ֱ��Ӧ�˴������д���  
                //int x = d.div(5,0);  
                //int x = d.div(4,1);  
                System.out.println("x="+x);   
        }  
        catch (ArithmeticException e)  
        {  
            System.out.println(e.toString());  
        }  
        catch (ArrayIndexOutOfBoundsException e)  
        {  
            System.out.println(e.toString());  
        }  
        catch (Exception e)//���� д�ڴ˴���Ϊ�˲�׽����ûԤ�ϵ����쳣 ֻ��д�������쳣�Ĵ������  
                            //����һ��������ǲ�д��   
        {  
            System.out.println(e.toString());  
        }  
          
  
  
        System.out.println("Over");  
    }  
  
} 