public class java {
/**
* @param args
*/
public int a;
public int b;
public int c;
public int getC() {
return c;
}
public void setC(int c) {
this.c = c;
}
public int getA() {
return a;
}
public void setA(int a) {
this.a = a;
}
public int getB() {
return b;
}
public void setB(int b) {
this.b = b;
}
public static void main(String[] args) {
// TODO Auto-generated method stub
int max=0;
java j=new java();
j.setA(5);
j.setB(4);
j.setC(2);
max=j.getA();
if(j.getB()>max)
{
max=j.getB();
if(j.getC()>max)
{
max=j.getC();
}
}
else if(j.getB()<max)
{
if(j.getC()>max)
{
max=j.getC();
}
}
System.out.println("最大的数为："+max);
}
}