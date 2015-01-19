#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) 
{
	fstream fin("garage.in");
	ofstream fout("garage.out");
	
	int W, H, w, h; fin >> W >> H >> w >> h;
	
	// width
	int w_ans = 1;
	for(int i = 0; i < W; i++)
	{
		double space = ( (double)W - (double)i * (double)w ) / ( (double)i + (double)1 );
		if(space < w)
		{
			w_ans = i;
			break;
		}
	}
	
	// height
	int h_ans = 1;
	for(int i = 0; i < H; i++)
	{
		double space = ( (double)H - (double)i * (double)h ) / ( (double)i + (double)1 );
		if(space < h)
		{
			h_ans = i;
			break;
		}
	}
	fout << w_ans * h_ans << endl;
}