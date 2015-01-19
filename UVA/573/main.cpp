#include <iostream>

using namespace std;

int H, U, D, F;

void solve()
{
	double toclimb = (double) U;
	double loosing = U * ((double)F) / 100.0;
	
	int day = 1;
	double height = 0;
	bool success = false;
	while(true)
	{
		// climb
		if(toclimb > 0) height += toclimb;
		toclimb -= loosing;
		
		if(height > H)
		{
			success = true;
			break;
		}
		
		// slide down
		height -= D;
		if(height < 0) break;
		
		day++;
	}
	
	if(success) cout << "success on day " << day << endl;
	else cout << "failure on day " << day << endl;
}

int main(int argc, char *argv[]) 
{
	while(true)
	{
		cin >> H >> U >> D >> F;
		if(H == 0) break;
		solve();
	}
}