#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

void solve(int h, int m)
{
	double m_a = (360.0 / 60.0) * (double)m;
	double h_a = (360.0 / 12.0) * (double)h + (360.0 / 60.0 / 12.0) * (double)m;
	double diff = abs(h_a - m_a);
	printf("%.3f\n", min(diff, 360.0 - diff));
}

int main(int argc, char *argv[]) 
{
	while(true)
	{
		string s; cin >> s;
		char *pch;
		pch = strtok(&s[0], ":");
		int h, m;
		stringstream(pch) >> h;
		pch = strtok(NULL, ":");
		stringstream(pch) >> m;
		if(h == 0 && m == 0) break;
		solve(h, m);
	}
}