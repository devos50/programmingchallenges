#include <iostream>

using namespace std;

void solve(int n)
{
	int tot = 0;
	int balls[n];
	for(int i = 0; i < n; i++)
	{
		cin >> balls[i];
		tot += balls[i];
	}
	
	if(tot % 2 == 1)
	{
		cout << "No equal partitioning." << endl;
		return;
	}
	
	int balls_per = tot / 2; int cur = 0; int curballs = 0; bool pos = false;
	while(true)
	{
		curballs += balls[cur];
		if(curballs == balls_per) { pos = true; break; }
		else if(cur == n) break;
		else if(curballs > balls_per) break;
		
		cur++;
	}
	
	if(!pos)
	{
		cout << "No equal partitioning." << endl;
		return;
	}
	else
	{
		cout << "Sam stops at position " << cur + 1 << " and Ella stops at position " << cur + 2 << "." << endl;
		return;
	}
}

int main(int argc, char *argv[]) 
{
	int n;
	while(true)
	{
		cin >> n;
		if(n == 0) break;
		
		solve(n);
	}
}