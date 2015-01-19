import java.util.*;
import java.math.*;

public class Main 
{
	public void solve(Scanner sc)
	{
		BigInteger num1 = new BigInteger(sc.next());
		BigInteger num2 = new BigInteger(sc.next());
		BigInteger rev = reverseNumber(num1).add(reverseNumber(num2));
		System.out.println(reverseNumber(rev));
	}
	
	public BigInteger reverseNumber(BigInteger num)
	{
		String snum = "" + num.toString();
		String rev = "";
		for(int i = snum.length() - 1; i >= 0; i--)
			rev += snum.charAt(i);
		return new BigInteger(rev);
	}
	
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int i = 0; i < t; i++) new Main().solve(sc);

	}

}
