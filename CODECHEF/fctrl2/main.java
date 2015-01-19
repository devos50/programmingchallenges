import java.util.*;
import java.math.*;

class Main 
{
	static BigInteger factorials[] = new BigInteger[101];
	
	public void solve(Scanner sc)
	{
		int n = sc.nextInt();
		System.out.println(factorials[n]);
	}
	
	public static void main(String[] args) 
	{
		// preprocess
		factorials[0] = BigInteger.ONE;
		for(int i = 1; i <= 100; i++)
			factorials[i] = factorials[i-1].multiply(BigInteger.valueOf(i));
		
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int i = 0; i < t; i++) new Main().solve(sc);
	}
}