class Watersource
{
	private int i;
	Watersource()
	{
		System.out.println("Watersource();");
	}
	public void plus()
	{
		i++;
	}
	public void iout()
	{
		System.out.println(i);
	}
}

public class Spring extends Watersource
{
	Spring()
	{
		System.out.println("Spring();");
	}

	public static void main(String[] args)
	{
		Spring s = new Spring();
		s.plus();
		s.iout();

		Watersource x = new Watersource();
		x.plus();
		x.iout();
		x.i = 3;
		x.iout();
	}
}