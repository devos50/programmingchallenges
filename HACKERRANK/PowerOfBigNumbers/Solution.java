
import java.math.BigInteger;
import java.util.Scanner;

public class Solution 
{
	public void solve(Scanner sc)
	{
		String a = sc.next();
		String b = sc.next();
		
		BigInteger aBig = new BigInteger(a);
		BigInteger bBig = new BigInteger(b);
		System.out.println(aBig.modPow(bBig, new BigInteger("1000000007")));
		
	}
	
	public static void main(String args[])
	{
		/*
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int i = 0; i < t; i++) new Solution().solve(sc);
		*/
		for(int i = 0; i < 10; i++) {
		// test
		StringBuilder sb = new StringBuilder();
		for(int j = 0; j < 100000; j++) sb.append("1");
		String str = sb.toString();
		BigInteger bi = new BigInteger(str);
		
		for(int j = 0; j < 100000; j++) bi.divide(new BigInteger("2"));
		System.out.println("HERE");
		
		}
	}
}
