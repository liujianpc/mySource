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
		System.out.println("名字:"+name+"\t性别:"+sex+"\t年龄"+age+"\t学号"+sID+"\t专业"+major);
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
		System.out.println("名字:"+name+"\t性别:"+sex+"\t年龄"+age+"\t教师号"+tID+"\t部门"+department);
	}
}

public class education
{
	public static void main(String[] args)
	{
		student stu = new student();
		teacher tea = new teacher();
		stu.setData("刘坚",'男',20,"2013060104021","计算机");
		tea.setData("李明",'女',30,"2015060104","通信");
		stu.getMessage();
		tea.getMessage();
		
	}
	
}