import java.math.BigInteger;
import java.util.*;

class Prex5 {
	
	public static void main(String[] args) 
	{
		// declare p, g and h
		BigInteger p = new BigInteger("13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084171");
		BigInteger g = new BigInteger("11717829880366207009516117596335367088558084999998952205599979459063929499736583746670572176471460312928594829675428279466566527115212748467589894601965568");
		BigInteger h = new BigInteger("3239475104050450443565264378728065788649097520952449527834792452971981976143292558073856937958553180532878928001494706097394108577585732452307673444020333");
		
		Set<BigInteger> hashTable = new HashSet<BigInteger>();
		Map<BigInteger, Integer> map = new HashMap<BigInteger, Integer>();
		
		BigInteger curG = g;
		
		// build the hash table
		for(int x = 1; x <= 1 << 20; x++)
		{
			// System.out.println("x: " + x);
			BigInteger newVal = h.multiply(curG.modInverse(p)).mod(p);
			hashTable.add(newVal);
			// System.out.println(newVal);
			curG = curG.multiply(g).mod(p);
			
			map.put(newVal, x);
			
			if(x % 10000 == 0) System.out.println(x);
		}
		
		System.out.println("----- building hash table done, evaluating the function");
		
		for(int x = 1; x <= 1 << 20; x++)
		{
			BigInteger b = new BigInteger("" + x);
			b = b.multiply(new BigInteger("" + (1 << 20)));
			BigInteger i = g.modPow(b, p);
			
			if(hashTable.contains(i))
			{
				System.out.println("----- answer found -----");
				System.out.println("x0: " + x);
				System.out.println("x1: " + map.get(i));
				
				break;
			}
		}
	}
}