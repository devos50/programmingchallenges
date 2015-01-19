#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long power(long long a, long long b) // calculate a^b
{
	long long n = a;
	if(b == 0) return 1;
	
	for(int i = 0; i < b - 1; i++) n *= a;
	return n;
}

long long calc_u_n(long long n)
{
	return 1 - n + power(n, 2) - power(n, 3) + power(n, 4) - power(n, 5) + power(n, 6) - power(n, 7) + power(n, 8) - power(n, 9) + power(n, 10);
}

void print_observation_matrix(int n)
{
	for(long long i = 1; i <= n; i++)
	{
		for(long long j = 0; j < n; j++)
		{
			cout << power(i, j) << " ";
		}
		cout << endl;
	}
}

void eval_poly(vector<long long> poly, int n)
{
	cout << "the first 10 solutions of the poly: " << endl;
	for(int i = 1; i <= 10; i++)
	{
		long long ans = 0;
		for(long long j = 0; j < n; j++)
		{
			ans += (poly[j] * power(i, j));
		}
		cout << ans << " ";
		if(calc_u_n(i) != ans) cout << "- NOT FIT";
		cout << endl;
	}
}

int main(int argc, char *argv[]) 
{
	fstream fin("terms.txt");
	int n; fin >> n;
	vector<long long> poly;
	for(int i = 0; i < n; i++)
	{
		long long l; fin >> l;
		poly.push_back(l);
	}
	
	// eval_poly(poly, n);
	
	print_observation_matrix(11);
}