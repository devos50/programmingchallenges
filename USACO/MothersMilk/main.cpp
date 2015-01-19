/*
 ID: mdmarti1
 PROG: milk3
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

set<int> bfs(int a, int b, int c)
{
	set<int> pos;
	queue<int> q;
	map<int, bool> visited;
	
	// initially only c is full
	q.push(c);
	visited[c] = true;
	
	while(q.size() != 0)
	{
		int code = q.front(); q.pop();
		int milkC = code % 100; code /= 100;
		int milkB = code % 100; code /= 100;
		int milkA = code;
		
		if(milkA == 0) pos.insert(milkC);
		
		// pour milk (a -> b)
		int milkToPour = min(milkA, b - milkB);
		int newcode = (milkA - milkToPour) * 10000 + (milkB + milkToPour) * 100 + milkC;
		if(!visited[newcode]) { visited[newcode] = true; q.push(newcode); }
		// pour milk (a -> c)
		milkToPour = min(milkA, c - milkC);
		newcode = (milkA - milkToPour) * 10000 + milkB * 100 + (milkC + milkToPour);
		if(!visited[newcode]) { visited[newcode] = true; q.push(newcode); }
		// pour milk (b -> a)
		milkToPour = min(milkB, a - milkA);
		newcode = (milkA + milkToPour) * 10000 + (milkB - milkToPour) * 100 + milkC;
		if(!visited[newcode]) { visited[newcode] = true; q.push(newcode); }
		// pour milk (b -> c)
		milkToPour = min(milkB, c - milkC);
		newcode = milkA * 10000 + (milkB - milkToPour) * 100 + (milkC + milkToPour);
		if(!visited[newcode]) { visited[newcode] = true; q.push(newcode); }
		
		// pour milk (c -> a)
		milkToPour = min(milkC, a - milkA);
		newcode = (milkA + milkToPour) * 10000 + milkB * 100 + (milkC - milkToPour);
		if(!visited[newcode]) { visited[newcode] = true; q.push(newcode); }
		// pour milk (c -> b)
		milkToPour = min(milkC, b - milkB);
		newcode = milkA * 10000 + (milkB + milkToPour) * 100 + (milkC - milkToPour);
		if(!visited[newcode]) { visited[newcode] = true; q.push(newcode); }
	}
	
	return pos;
}

int main()
{
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
    int a, b, c;
    fin >> a >> b >> c;
    
	set<int> pos = bfs(a, b, c);
	vector<int> v;
	for(set<int>::iterator it = pos.begin(); it != pos.end(); it++) v.push_back(*it);
	
	sort(v.begin(), v.end());
	
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		fout << *it;
		if(it + 1 != v.end()) fout << " ";
	}
	fout << endl;
	
    return 0;
}