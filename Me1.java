class Me1 {
    String eat(String food){
        //food�ǲ���
       String s ="�������";
        System.out.println("����ˮ�ֳ�"+food);
        //s�Ƿ���ֵ,����һ������ʱ�ùؼ���return��Ϊ���������String���͵ģ����Է���ֵҲ��String����
        return s;
    }
    public static void main(String[] args) {
      Me1 m= new Me1();
      //����eat����������food������������String���͵ģ�
      System.out.println(m.eat("����"));
    }
	}