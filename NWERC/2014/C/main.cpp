#include <iostream>
#include <vector>

using namespace std;

vector<int> parts;
vector<int> newparts;

int main(int argc, char *argv[]) 
{
	int n, d; cin >> n >> d;
	for(int i = 0; i < n; i++) { int v; cin >> v; parts.push_back(v); }
	
	do 
	{
		int curp = parts[0];
		for(int i = 1; i < parts.size(); i++)
		{
			// if adding cur item implies rounding up
			if((curp + parts[i]) % 10 >= 5) 
			{
				newparts.push_back(curp);
				curp = parts[i];
			}
			else // if not, just add it to curp
			{
				curp += parts[i];
			}
		}
		newparts.push_back(curp);
		
		// if we cannot do anything, just split it
		if(parts.size() == newparts.size()) 
		{
			  
		}
		
		parts = newparts;
		newparts = vector<int>();
		
		for(int i = 0; i < parts.size(); i++)
		{
			cout << parts[i] << " ";
		}
		cout << endl;
		
	} while(parts.size() - 1 > d);
	
	// calculate the sum
	int ans = 0;
	for(int i = 0; i < parts.size(); i++)
	{
		if(parts[i] % 10 > 5) { ans += parts[i] / 10 * 10 + 10; }
		else { ans += parts[i] / 10 * 10; }
	}
}