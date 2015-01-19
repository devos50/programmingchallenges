/*
ID: mdmarti1
LANG: JAVA
TASK: nocows
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int rec2(int n, int k);

	int table[205][105]; int c[205][105];
		
	int rec(int n, int k){
	  		if(n==1 && k==1) return 1;
	  		if(n==1 && k>1) return 0;
	  		if(k==0) return 0;
	  		if(table[n][k]!=-1) return table[n][k];
	  		int res = 0;
	  		
	  		for(int nleft=1;nleft<n-1;nleft++){
	  			int nright = n-nleft-1;
	  			int sum = (rec2(nleft,k-2)*rec(nright,k-1))%9901;
	  			res += sum;
	  			res %= 9901;
	  			sum = (rec2(nleft,k-2)*rec(nright,k-1))%9901;
	  			res += sum;
	  			res %= 9901;
	  			res += rec(nleft,k-1)*rec(nright,k-1);
	  			res %= 9901;
	  		}
	  		table[n][k] = res;
	  		return res;
	  	}
	  	
	  	 int rec2(int n, int k){
	  		if(k<0) return 0;
	  		if(c[n][k]!=-1) return c[n][k];
	  		int sum = 0;
	  		for(int kleft=1;kleft<=k;kleft++){
				int kright = k-1;
				sum += rec(n,kleft);
				sum %= 9901;
				c[n][kleft] = sum;
			}
			return sum;
	  	}
		
	int main()
	{
	    ofstream fout ("nocows.out");
	    ifstream fin ("nocows.in");
	    int n, k;
	    fin >> n >> k;
	
	for(int i = 0; i < 205; i++)
		for(int j = 0; j < 105; j++)
		{
			table[i][j] = -1;
			c[i][j] = -1;
		}
			
	
		    for(int i=0;i<=n;i++){
		    	for(int j=0;j<=k;j++){
		    		table[i][j] = rec(i,j);
		    	}
		    }
		    int res = rec(n,k);
		    
		fout << res << endl;
		//System.out.println(res);
		  //  out.println(res);
	
	    return 0;
	}
	/*	
  	public static void main (String [] args) throws IOException {
  		long t = System.currentTimeMillis();
	    Scanner sc = new Scanner(new File("nocows.in"));
	    out = new PrintWriter(new File("nocows.out"));
	    
	    int n = sc.nextInt();
	    int k = sc.nextInt();
	    
	    System.out.println(System.currentTimeMillis()-t); 
	    
	    out.close();
	    System.exit(0);
  	}
  	*/