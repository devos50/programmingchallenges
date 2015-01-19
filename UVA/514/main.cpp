#include <iostream>
#include <stack>

using namespace std;

void solve(int n)
{
	while(true)
	{
		bool ispos = true;
		int order[n];
		bool instation[n]; for(int i = 0; i < n; i++) instation[i] = false;
		int p; cin >> p;
		// cout << "p: " << p << endl;
		if(p == 0) break;
		else order[0] = p - 1;
		for(int i = 1; i < n; i++) { cin >> order[i]; order[i]--; }
		
		stack<int> station;
		for(int i = 0; i < n; i++)
		{
			int tofind = order[i];
			// cout << "to find: " << tofind << endl;
			if(station.size() > 0 && station.top() == tofind) // in station
			{
				// cout << "popping " << tofind << " from the stack" << endl;
				station.pop();
			}
			else if(instation[tofind])
			{
				// cout << tofind << " NOT ON TOP " << endl;
				ispos = false;
				break;
			}
			else
			{
				for(int i = 0; i < tofind; i++)
					if(!instation[i]) { station.push(i); instation[i] = true; }
				instation[tofind] = true;
			}
		}
		if(ispos) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}

int main(int argc, char *argv[]) 
{
	int n;
	while(true)
	{
		cin >> n;
		if(n == 0) break;
		solve(n);
		cout << endl;
	}
}