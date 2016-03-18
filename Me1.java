class Me1 {
    String eat(String food){
        //food是参数
       String s ="获得力量";
        System.out.println("大力水手吃"+food);
        //s是返回值,返回一个参数时用关键字return因为这个方法是String类型的，所以返回值也是String类型
        return s;
    }
    public static void main(String[] args) {
      Me1 m= new Me1();
      //调用eat方法，传入food参数，由于是String类型的，
      System.out.println(m.eat("菠菜"));
    }
	}