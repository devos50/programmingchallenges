#include <iostream>
#include <set>

#define N 10
#define E 30

using namespace std;

set<pair<int, int> > edges;

int main(int argc, char *argv[]) 
{
	cout << N << " " << E << " " << 1 << endl;
	for(int i = 0; i < E; i++)
	{
		int e1, e2;
		do
		{
			 e1 = rand() % N;
			 e2 = rand() % N;
			while(e2 == e1) e2 = rand() % N;
		} while(edges.find(make_pair(e1, e2)) != edges.end());
		
		edges.insert(make_pair(e1, e2));
		cout << e1 << " " << e2 << endl;
	}
}