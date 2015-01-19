import java.math.BigInteger;

class Crypto2
{
	public static BigInteger bigIntSqRootCeil(BigInteger x)
	        throws IllegalArgumentException {
	    if (x.compareTo(BigInteger.ZERO) < 0) {
	        throw new IllegalArgumentException("Negative argument.");
	    }
	    // square roots of 0 and 1 are trivial and
	    // y == 0 will cause a divide-by-zero exception
	    if (x == BigInteger.ZERO || x == BigInteger.ONE) {
	        return x;
	    } // end if
	    BigInteger two = BigInteger.valueOf(2L);
	    BigInteger y;
	    // starting with y = x / 2 avoids magnitude issues with x squared
	    for (y = x.divide(two);
	            y.compareTo(x.divide(y)) > 0;
	            y = ((x.divide(y)).add(y)).divide(two));
	    if (x.compareTo(y.multiply(y)) == 0) {
	        return y;
	    } else {
	        return y.add(BigInteger.ONE);
	    }
	} // end bigIntSqRootCeil
	
	public static void main(String[] args) 
	{
		BigInteger n = new BigInteger("648455842808071669662824265346772278726343720706976263060439070378797308618081116462714015276061417569195587321840254520655424906719892428844841839353281972988531310511738648965962582821502504990264452100885281673303711142296421027840289307657458645233683357077834689715838646088239640236866252211790085787877");
		
		BigInteger a = bigIntSqRootCeil(n);
		
		while(true)
		{
			// test A
			BigInteger x = bigIntSqRootCeil(a.multiply(a).subtract(n));
					
			BigInteger p = a.subtract(x);
			BigInteger q = a.add(x);
			BigInteger prod = p.multiply(q);
			
			if(n.compareTo(prod) == 0)
			{
				System.out.println("p: " + p);
				System.out.println("q: " + q);
				System.out.println("prod: " + prod);
				break;
			}
			a = a.add(BigInteger.ONE);
		}
	}
}