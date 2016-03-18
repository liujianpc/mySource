enum Car
{
	dasAuto(100),audio(200),benze(300),ford(400);
	private int price;
	Car(int p)
	{
		price = p;
	}

	int getPrice()
	{
		return price;
	}
}

public class enumClass
{
	public static void main(String[] args)
	{
		for(Car c : Car.values())
		{
			System.out.println(c+"ะ่าช"+c.getPrice());
		}
	}
}