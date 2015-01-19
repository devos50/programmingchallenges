#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool can = false;

double eval(double a, double b, int op)
{
	if(op == 0) return a + b;
	else if(op == 1) return a - b;
	else if(op == 2) return a * b;
	else if(op == 3) return a / b;
	
	return 0;
}

void rec(vector<double> vec)
{
	// for(vector<double>::iterator it = vec.begin(); it != vec.end(); it++) cout << *it << " ";
	// cout << endl;
	// cout << "vec size: " << vec.size() << endl;
	if(vec.size() == 1)
	{
		// cout << "VALUE: " << vec[0] << endl;
		if(abs(vec[0] - 24.0) < 0.0001) { can = true; }
		return;
	}
	
	// chose two indices and take an operator
	for(int i = 0; i < vec.size() - 1; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(j == 3 && vec[i+1] == 0) continue;
			vector<double> newvec;
			for(int k = 0; k < i; k++) newvec.push_back(vec[k]);
			newvec.push_back(eval(vec[i], vec[i+1], j));
			for(int k = i + 2; k < vec.size(); k++) newvec.push_back(vec[k]);
			rec(newvec);
		}
	}
}

void solve()
{
	can = false;
	double a, b, c, d; cin >> a >> b >> c >> d;
	// cout << a << " " << b << " " << c << " " << d << endl;
	vector<double> vec;
	vec.push_back(a); vec.push_back(b); vec.push_back(c); vec.push_back(d);
	sort(vec.begin(), vec.end());
	
	do {
		rec(vec);
	} 
	while(next_permutation(vec.begin(), vec.end()));
	
	if(can) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}