#include <iostream>

#define LL long long

using namespace std;

int size, p;

void solve()
{
	// vind laagste oneven kwadraat onder p
	LL n = 1;
	int count = -1;
	if(p == 1) { cout << "Line = " << size / 2 + 1 << ", column = " << size / 2 + 1 << "." << endl; return; }
	while(n * n < p) { n += 2; count++; }
	n -= 2;
	int sqrtn = n;
	n *= n;
	
	int curline = (size / 2) + 1 + count;
	int curcolumn = (size / 2) + 1 + count;
	int curn = n;
	
	// one up
	curline++;
	curn++;
	if(curn == p) { cout << "Line = " << curline << ", column = " << curcolumn << "." << endl; return; }
	
	// go left
	for(int i = 0; i < sqrtn; i++)
	{
		curcolumn--;
		curn++;
		if(curn == p) { cout << "Line = " << curline << ", column = " << curcolumn << "." << endl; return; }
	}
	
	// go down
	for(int i = 0; i < sqrtn + 1; i++)
	{
		curline--;
		curn++;
		if(curn == p) { cout << "Line = " << curline << ", column = " << curcolumn << "." << endl; return; }
	}
	
	// go right
	for(int i = 0; i < sqrtn + 1; i++)
	{
		curcolumn++;
		curn++;
		if(curn == p) { cout << "Line = " << curline << ", column = " << curcolumn << "." << endl; return; }
	}
	
	// go up
	for(int i = 0; i < sqrtn + 1; i++)
	{
		curline++;
		curn++;
		if(curn == p) { cout << "Line = " << curline << ", column = " << curcolumn << "." << endl; return; }
	}
}

int main(int argc, char *argv[]) 
{
	while(true)
	{
		cin >> size >> p;
		if(size == 0 && p == 0) break;
		solve();
	}
}