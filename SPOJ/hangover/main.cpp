#include <iostream>

using namespace std;

double values[300];

void precalc()
{
	values[0] = 0.0; values[1] = 0.5;
	for(int i = 1; i < 300; i++)
	{
		values[i] = values[i-1] + 1.0 / (double)(i + 1);
	}
}

void solve(double cur)
{
	int cards = 0;
	for(int i = 0; i < 300; i++)
	{
		if(values[i] > cur) { cards = i; break; }
	}
	cout << cards << " card(s)" << endl;
}

int main(int argc, char *argv[]) 
{
	precalc();
	while(true)
	{
		double cur; cin >> cur;
		if(cur == 0.0) break;
		solve(cur);
	}
}