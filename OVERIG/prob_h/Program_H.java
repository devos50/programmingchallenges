import java.util.Scanner;


public class Program_H {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		boolean run = true;
		System.out.println("Type -1 to quit.");
		
		while (run)
		{
			System.out.println("Input:");
			
			int input = scan.nextInt();
			
			if (input == -1)
			{
				run = false;
				return;
			}
			else
			{
				System.out.println(triangle(input));
				
			}
		}
	}
	
	public static long triangle(int n)
	{
		long triangles = 1;
		long plus = 3;
		long step = 3;
		
		for (int i = 1; i < n; i++)
		{
			triangles += plus;
			plus += step;
			step ++;
		}
		return triangles;
	}

}
