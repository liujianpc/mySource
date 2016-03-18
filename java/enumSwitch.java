enum Car{dasAuto,audio,toyota,honda,benze};
public class enumSwitch
{
	public static void main(String[] args)
	{
		Car c = Car.audio;
		switch(c)
		{
			case dasAuto:
				System.out.println("you choosed dasAuto");
				break;
			case audio:
				System.out.println("you choosed audio");
				break;
			case toyota:
				System.out.println("you choosed toyota");
				break;
			case honda:
				System.out.println("you choosed honda");
				break;
			case benze:
				System.out.println("you choosed benze");
				break;
			default:
				System.out.println("you choosed nothing");
		}
	}
}