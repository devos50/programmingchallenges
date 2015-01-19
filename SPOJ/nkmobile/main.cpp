#include <iostream>

using namespace std;

int square[1028][1028];

int main(int argc, char *argv[]) 
{
	int instr, S; cin >> instr >> S;
	
	for(int y = 0; y < S; y++)
		for(int x = 0; x < S; x++)
			square[y][x] = 0;
	
	cin >> instr;
	while(instr != 3)
	{
		if(instr == 1)
		{
			long long x, y, a; cin >> x >> y >> a;
			square[y][x] += a;
		}
		else if(instr == 2)
		{
			long long l, b, r, t; cin >> l >> b >> r >> t;
			long long ans = 0;
			for(long long y = b; y <= t; y++)
				for(long long x = l; x <= r; x++)
					ans += square[y][x];
			cout << ans << endl;
		}
		
		cin >> instr;
	}
}