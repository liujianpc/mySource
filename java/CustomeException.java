class wrongInput extends Exception
{
	wrongInput(String s)
	{
		super(s);
	}
}

class input
{
	void throwError() throws wrongInput
	{
		throw new wrongInput(" ‰»Î¥ÌŒÛ£°");
	}
}

class CustomeException
{
	public static void main(String[] args)
	{
		try
		{
			input in = new input();
			in.throwError();
		}
		catch(wrongInput e)
		{
			System.out.println("¥ÌŒÛ–≈œ¢"+ e);
		}
	}
}