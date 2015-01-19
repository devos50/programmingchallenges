#include <iostream>
#include <vector>

#define MAX 1000010

using namespace std;

bool times[MAX];

typedef struct Reptask {
	int start, end, rep;
} Reptask;

typedef struct Task {
	int start, end;
} Task;

void solve(int n, int m)
{
	vector<Task> tasks;
	vector<Reptask> reptasks;
	
	for(int i = 0; i < n; i++)
	{
		Task t; cin >> t.start >> t.end;
		tasks.push_back(t);
	}
	for(int i = 0; i < m; i++)
	{
		Reptask t; cin >> t.start >> t.end >> t.rep;
		reptasks.push_back(t);
	}
	
	for(int i = 0; i < MAX; i++) times[i] = false;
	
	for(int i = 0; i < n; i++)
	{
		int s, t; s = tasks[i].start, t = tasks[i].end;
		for(int j = s + 1; j <= t; j++)
		{
			if(times[j]) 
			{
				cout << "CONFLICT" << endl; 
				return; 
			}
			times[j] = true;
		}
	}
	
	// repeating tasks
	for(int i = 0; i < m; i++)
	{
		int s, t, d; s = reptasks[i].start, t = reptasks[i].end, d = reptasks[i].rep;
		for(int j = s + 1; j + (t - s) < MAX; j += d)
		{
			for(int k = j; k < j + (t - s); k++)
			{
				if(times[k]) 
				{
					cout << "CONFLICT" << endl; 
					return; 
				}
				times[k] = true;
			}
		}
	}
	
	cout << "NO CONFLICT" << endl;
}

int main(int argc, char *argv[]) 
{
	int n, m;
	while(true)
	{
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		// cout << "n: " << n << ", m: " << m << endl;
		solve(n, m);
	}
}