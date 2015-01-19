import java.util.*;

class leexams{
	public static boolean[] used;
	public static int n;
	public static int[] p,a,b;
	
	public static void main(String[] args){
		Locale.setDefault(Locale.US);
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i=0;i<n;i++){
			solve(sc);
		}
	}
	
	public static void solve(Scanner sc){
		n = sc.nextInt();
		if(n>16){
			System.out.printf("%.9f\n",0.0);
			return;
		}
		used = new boolean[17];
		p = new int[n];
		a = new int[n];
		b = new int[n];
		for(int i=0;i<n;i++){
			p[i] = sc.nextInt();
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
		}
		System.out.printf("%.9f\n",rec(0));
	}
	
	public static double rec(int ind){
		if(ind>=n) return 1;
		double res = 0;
		if(!used[a[ind]]){
			used[a[ind]] = true;
			res += (p[ind]/100.0)*rec(ind+1);
			used[a[ind]] = false;
		}
		if(!used[b[ind]]){
			used[b[ind]] = true;
			res += ((100-p[ind])/100.0)*rec(ind+1);
			used[b[ind]] = false;
		}
		return res;
	}
}