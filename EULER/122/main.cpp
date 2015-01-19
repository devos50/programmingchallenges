#include <iostream>
#include <vector>

#define ITERATIONS 10

using namespace std;

int main(int argc, char *argv[]) 
{
	// start with (1, 0) => means n^1 with 0 operations
	pair<int, int> start_pair = make_pair(1, 0);
	bool have[100000]; for(int i = 0; i < 100000; i++) have[i] = false;
	int calcs[100000]; for(int i = 0; i < 100000; i++) calcs[i] = 1000000;
	have[1] = true;
	calcs[1] = 0;
	
	vector<int> vec; vec.push_back(1);
	
	for(int i = 1; i <= ITERATIONS; i++)
	{
		vector<int> toadd;
		
		for(int j = 0; j < vec.size(); j++)
		{
			for(int k = 0; k < vec.size(); k++)
			{
				int n1 = vec[j];
				int n2 = vec[k];
				int newexp = n1 + n2;
				pair<int, int> new_pair = make_pair(newexp, calcs[n1] + calcs[n2] + 1);
				if(!have[newexp])
				{
					have[newexp] = true;
					calcs[newexp] = calcs[n1] + calcs[n2] + 1;
					if(n1 == n2) calcs[newexp] = calcs[n1] + 1;
					cout << "pushing n^" << newexp << "from n^" << n1 << " and n^" << n2 << " with " << calcs[newexp] << " calculations " <<  endl;
					toadd.push_back(newexp);
				}
				else if(calcs[n1])
			}
		}
		
		cout << "-- next calculation --" << endl;
		
		// add to vec
		for(int j = 0; j < toadd.size(); j++)
			vec.push_back(toadd[j]);
	}
	
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << "n^" << *it << ": " << calcs[*it] << endl;
	}
}