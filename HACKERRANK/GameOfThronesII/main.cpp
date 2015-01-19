#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000007

long long degree(long long a, long long k, long long p) {
  long long res = 1;
  long long cur = a;

  while (k) {
    if (k%2) {
      res = (res * cur)%p;
    }
    k /= 2;
    cur = (cur * cur) % p;
  }
  return res;
}

int get_degree(long long n, long long p) { // returns the degree with which p is in n!
  int degree_num = 0;
  long long u = p;
  long long temp = n;
  while (u <= temp) {
    degree_num += temp/u;
    u *= p;
  }
  return degree_num;
}

long long combinations(int n, int k, long long p) {
  int num_degree = get_degree(n,p) - get_degree(n- k,p);
  int den_degree = get_degree(k,p);
  if (num_degree > den_degree) {
    return 0;
  }
  long long res = 1;
  for (long long i = n; i > n- k; --i) {
    long long ti = i;
    while(ti % p == 0) {
      ti /= p;
    }
    res = (res *ti)%p;
  }
  for (long long i = 1; i <= k; ++i) {
    long long ti = i;
    while(ti % p == 0) {
      ti /= p;
    }
    res = (res * degree(ti, p-2, p))%p;
  }
  return res;
}

int main() 
{
    vector<long long> denumfacts;
    
    string s; cin >> s;
    long long freq[26]; for(long long i = 0; i < 26; i++) freq[i] = 0;
    for(long long i = 0; i < s.size(); i++) freq[s[i] - 'a']++;
    
    for(long long i = 0; i < 26; i++)
        if(freq[i] % 2 == 1) freq[i]--;
    
    long long evenletters = 0;
    for(int i = 0; i < 26; i++)
	{
        if(freq[i] % 2 == 0 && freq[i] != 0)
        {
            denumfacts.push_back(freq[i] / 2);
            evenletters += (freq[i] / 2);
        }
	}
    
	// calculate multinomial coefficient
	long long num = 0;
	long long ans = 1;
	for(int i = 0; i < denumfacts.size(); i++)
	{
		num += denumfacts[i];
		ans *= combinations(num, denumfacts[i], MOD);
		ans %= MOD;
	}
	
	cout << ans << endl;
    
    return 0;
}
