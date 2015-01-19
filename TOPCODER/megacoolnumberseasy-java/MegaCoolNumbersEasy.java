public class MegaCoolNumbersEasy {

	public boolean isCool(int n)
	{
		if(n >= 1 && n <= 9) return true;
		
		String s = "" + n;
		int between = s.charAt(1) - s.charAt(0);
		for(int i = 1; i < s.length() - 1; i++)
		{
			if(s.charAt(i + 1) - s.charAt(i) == between) continue;
			else return false;
		}
		return true;
	}
	
	public int count(int N) 
	{
		int ans = 0;
		for(int i = 1; i <= N; i++)
		{
			if(isCool(i)) ans++;
		}
		return ans;
	}

}
