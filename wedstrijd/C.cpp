#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

priority_queue<int> ql;
priority_queue<int, vector<int>, greater<int> > qr;

void balance();

int abs_v(int n)
{
	if(n < 0) return n * -1;
	return n;#include <iostream>
	#include <queue>
	#include <sstream>

	using namespace std;

	priority_queue<int> ql;
	priority_queue<int, vector<int>, greater<int> > qr;

	void balance();

	int abs_v(int n)
	{
		if(n < 0) return n * -1;
		return n;
	}

	int median(bool rem)
	{
		if(qr.size() == 0) return 0;
		
		int med = qr.top();
		if(rem) { qr.pop(); balance(); }
		return med;
	}

	void balance()
	{
		// cout << "ql size: " << ql.size() << ", qr size: " << qr.size() << endl;
		
		if(abs_v(ql.size() - qr.size()) > 1)
		{
			if(ql.size() > qr.size())
			{
				int med = ql.top();
				ql.pop();
				qr.push(med);
			}
			else
			{
				int med = qr.top();
				// cout << "med: " << med << endl;
				qr.pop();
				ql.push(med);
			}
		}
		
		if(ql.size() - 1 == qr.size())
		{
			int med = ql.top();
			ql.pop();
			qr.push(med);
		}
		
		// cout << "ql size: " << ql.size() << ", qr size: " << qr.size() << endl;
	}

	void insert(int n)
	{	
		int m = median(false);
		if(m < n)
			qr.push(n);
		else
			ql.push(n);
			
		balance();
	}

	int main(int argc, char *argv[]) 
	{
		string s;
		while(cin >> s)
		{
			if(s == "#") cout << median(true) << endl;
			else
			{
				int n;
				stringstream ss(s); ss >> n;
				insert(n);
			}
		}
	}}

int median(bool rem)
{
	if(qr.size() == 0) return 0;
	
	int med = qr.top();
	if(rem) { qr.pop(); balance(); }
	return med;
}

void balance()
{
	// cout << "ql size: " << ql.size() << ", qr size: " << qr.size() << endl;
	
	if(abs_v(ql.size() - qr.size()) > 1)
	{
		if(ql.size() > qr.size())
		{
			int med = ql.top();
			ql.pop();
			qr.push(med);
		}
		else
		{
			int med = qr.top();
			// cout << "med: " << med << endl;
			qr.pop();
			ql.push(med);
		}
	}
	
	if(ql.size() - 1 == qr.size())
	{
		int med = ql.top();
		ql.pop();
		qr.push(med);
	}
	
	// cout << "ql size: " << ql.size() << ", qr size: " << qr.size() << endl;
}

void insert(int n)
{	
	int m = median(false);
	if(m < n)
		qr.push(n);
	else
		ql.push(n);
		
	balance();
}

int main(int argc, char *argv[]) 
{
	string s;
	while(cin >> s)
	{
		if(s == "#") cout << median(true) << endl;
		else
		{
			int n;
			stringstream ss(s); ss >> n;
			insert(n);
		}
	}
}