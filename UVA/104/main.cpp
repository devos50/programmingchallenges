#include <iostream>
#include <stack>

using namespace std;

void solve(int d)
{
	double rates[d][d];
	for(int i = 0; i < d; i++)
		for(int j = 0; j < d; j++)
		{
			if(i == j) rates[i][j] = 1.0;
			else cin >> rates[i][j];
		}
		
	// floyd warshall
	double best[d][d][d+1];
	int path[d][d][d+1];
	for(int i = 0; i < d; i++)
		for(int j = 0; j < d; j++)
			best[i][j][1] = rates[i][j];
			
	for(int i = 0; i < d; i++)
				for(int j = 0; j < d; j++)
					path[i][j][1] = i;
			
	for(int steps = 2; steps <= d; steps++)
		for(int k = 0; k < d; k++)
			for(int i = 0; i < d; i++)
				for(int j = 0; j < d; j++)
				{
					double tmp = best[i][k][steps-1] * best[k][j][1];
					if(tmp > best[i][j][steps]) { best[i][j][steps] = tmp; path[i][j][steps] = k; }
				}
				
	// find the result
	stack<int> r;
	for(int steps = 2; steps <= d; steps++)
		for(int i = 0; i < d; i++)
		{
			if(best[i][i][steps] > 1.01)
			{
				int cur = path[i][i][steps];
				while(steps >= 1)
				{
					steps--;
					r.push(cur + 1);
					cur = path[i][cur][steps];
				}
				
				while(r.size() != 0)
				{
					cout << r.top() << " ";
					r.pop();
				}
				cout << i+1;
				cout << endl;
				
				return;
			}
		}
	cout << "no arbitrage sequence exists" << endl;
}

int main(int argc, char *argv[]) 
{
	int d;
	while(cin >> d) solve(d);
}