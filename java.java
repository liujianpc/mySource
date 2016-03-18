public class java {
/**
* @param args
*/
public int a=0;
public int b=0;

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
int min=0;
java j=new java();
j.setA(5);
j.setB(4);
if(j.getA()<j.getB())
{
min=j.getA();
}
else if(j.getA()>j.getB())
{
min=j.getB();
}
System.out.println("最小的数为："+min);
}
}