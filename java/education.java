abstract class People
{
	String name;
	char sex;
	int age;

	abstract void setData(String name,char sex,int age);
	abstract void getMessage();
}

class student extends People
{
	String sID;
	String major;
	void setData(String name,char sex,int age)
	{
		this.name = name;
		this.sex = sex;
		this.age = age;
	
		
	}
	
	void setData(String name,char sex,int age,String sID, String major)
	{
		this.name = name;
		this.sex = sex;
		this.age = age;
		this.sID = sID;
		this.major = major;
		
	}



	void getMessage()
	{
		System.out.println("����:"+name+"\t�Ա�:"+sex+"\t����"+age+"\tѧ��"+sID+"\tרҵ"+major);
	}
}

class teacher extends People
{
	String tID;
	String department;

	void setData(String name,char sex,int age)
	{
		this.name = name;
		this.sex = sex;
		this.age = age;
		
	}

	void setData(String name,char sex,int age,String tID,String department)
	{
		this.name = name;
		this.sex =sex;
		this.age = age;
		
		this.tID = tID;
		this.department = department;
	}

	void getMessage()
	{
		System.out.println("����:"+name+"\t�Ա�:"+sex+"\t����"+age+"\t��ʦ��"+tID+"\t����"+department);
	}
}

public class education
{
	public static void main(String[] args)
	{
		student stu = new student();
		teacher tea = new teacher();
		stu.setData("����",'��',20,"2013060104021","�����");
		tea.setData("����",'Ů',30,"2015060104","ͨ��");
		stu.getMessage();
		tea.getMessage();
		
	}
	
}