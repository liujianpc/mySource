  class Testjava {
     String c ="全局变量";
     void a(){
         String a="给我一份红烧肉";
         System.out.println(a);
         System.out.println(c);
     }
     void b(){
         String b="饭店:好嘞";
         System.out.println(b);
         System.out.println(c);
     }
	 
     public static void main(String[] args) {
         Testjava t=new Testjava();
         t.a();
         t.b();
     }
	 }