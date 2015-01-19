#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	
	double maxa = -1.0;
	double mina = 10E15;
	int minind = 0;
	int maxind = 0;
	
	for(int i = 0; i < n; i++)
	{
		double x1, x2, x3, y1, y2, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		
		double area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
		area /= 2.0;
		if(area < 0) area *= -1;
		
		if(area <= mina)
		{
			mina = area;
			minind = i + 1;
		}
		if(area >= maxa)
		{
			maxa = area;
			maxind = i + 1;
		}
	}
	cout << minind << " " << maxind << endl;
}