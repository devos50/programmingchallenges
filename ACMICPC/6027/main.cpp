#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

#define kAbsDist 0.00001
#define PI 3.14159265357989

using namespace std;

vector<pair<double, int> > coefficients; // ax^b

double evalPoly(double x)
{
	double ans = 0.0;
	for(vector<pair<double, int> >::iterator it = coefficients.begin(); it != coefficients.end(); it++)
	{
		double topower = 1.0; for(int i = 0; i < it->second; i++) topower *= x;
		ans += it->first * topower;
	}
	return ans;
}

double binarySearch(double low, double high, double tofind, double xlow)
{
	if(abs(high - low) < kAbsDist)
		return low;
		
	double mid = (high + low) / 2.0;
	double volume = PI * evalPoly(mid) - PI * evalPoly(xlow);
	if(volume < tofind)
		return binarySearch(mid, high, tofind, xlow);
	else
		return binarySearch(low, mid, tofind, xlow);
}

void solve(double xlow, double xhigh, double markerdist, int c)
{
	vector<pair<double, int> > newcoefficients;
	for(vector<pair<double, int> >::iterator it1 = coefficients.begin(); it1 != coefficients.end(); it1++)
		for(vector<pair<double, int> >::iterator it2 = coefficients.begin(); it2 != coefficients.end(); it2++)
			newcoefficients.push_back(make_pair(it1->first * it2->first, it1->second + it2->second));
	
	coefficients = newcoefficients;
	
	// integrate term by term
	for(vector<pair<double, int> >::iterator it = coefficients.begin(); it != coefficients.end(); it++)
	{
		double newfirst = it->first / (double)(it->second + 1);
		int newsecond = it->second + 1;
		it->first = newfirst; it->second = newsecond;
	}
	
	double volume = PI * evalPoly(xhigh) - PI * evalPoly(xlow);
	printf("Case %d: %.2f\n", c, volume);
	
	if(volume < markerdist)
	{
		cout << "insufficient volume" << endl;
		return;
	}
	
	// create the markers
	for(double i = markerdist; i <= volume && i <= 8 * markerdist; i += markerdist)
	{
		printf("%.2f", binarySearch(xlow, xhigh, i, xlow) - xlow);
		if(!(i + markerdist >= volume || i == 8 * markerdist)) cout << " ";
	}
	cout << endl;
}

int main(int argc, char *argv[]) 
{
	int n; int c = 1;
	while(cin >> n)
	{
		coefficients.clear();
		for(int i = 0; i < n + 1; i++) { double m; cin >> m; coefficients.push_back(make_pair(m, i)); }
		double xlow, xhigh, markerdist; cin >> xlow >> xhigh >> markerdist;
		solve(xlow, xhigh, markerdist, c);
		c++;
	}
}