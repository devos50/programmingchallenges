#include <stdio.h>

#define MAX 20005

int maxvalue(int a, int b)
{
	if(a > b) return a;
	else return b;
}

int main(int argc, char *argv[]) 
{
	int lengths[MAX];
	int values[MAX];
	
	int n, l;
	scanf("%d %d", &n, &l);
	int i;
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &lengths[i], &values[i]);
	}
	
	int dp1[MAX];
	int dp2[MAX];
	for( i = 0; i <= MAX; i++)
		dp1[i] = 0;
		
	for( i = 0; i < n; i++)
	{
		// cout << "HERE" << endl;
		int curlength = lengths[i];
		int curvalue = values[i];
		
		dp2[curlength] = maxvalue(dp1[curlength], curvalue);
		
		int j;
		for( j = 0; j <= l * 2; j++)
		{
			if(j == curlength) continue;
			if(j - curlength < 0) dp2[j] = dp1[j];
			else if (dp1[j - curlength] != 0) dp2[j] = maxvalue(dp1[j], dp1[j - curlength] + curvalue);
		}
		
		// copy dp2 -> dp1
		for( j = 0; j <= l * 2; j++)
			dp1[j] = dp2[j];
			
		// for(int j = 0; j <= l; j++)
		// 	cout << dp1[j] << " ";
		// cout << endl;
	}
	
	if(dp1[l] != 0) printf("%d\n", dp1[l]);
	else
	{
		// cout << "HERE" << endl;
		int cur = l;
		while(dp1[cur] == 0) cur++;
		printf("%d\n", dp1[cur]);
	}
	
	// cout << dp1[l] << endl;
	
	return 0;
}