#include <iostream>
#include <map>

using namespace std;

void solve(int loanDuration, double downPayment, double loan, int n)
{
	int m; double p;
	double decP[101];
	
	while(n--)
	{
		cin >> m >> p;
		for(int i = m; i < 101; i++) decP[i] = p;
	}
		
	int now = 0;
	double monthlyPayment = loan / loanDuration;
	double curVal = (loan + downPayment) * (1 - decP[0]);
	double curLoan = loan;
	while(curVal < curLoan)
	{
		now++;
		curLoan -= monthlyPayment;
		curVal = curVal * (1 - decP[now]);
	}
		
	cout << now << " month";
	if(now != 1) cout << "s";
	cout << endl;
}

int main(int argc, char *argv[]) 
{
	int loanDuration, n;
	double loan, carValue;
	while(true)
	{
		cin >> loanDuration >> loan >> carValue >> n;
		if(loanDuration < 0) break;
		solve(loanDuration, loan, carValue + loan, n);
	}
}