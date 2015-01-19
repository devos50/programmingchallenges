#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;
int n;

void printvec()
{
	for(vector<int>::iterator it = tree.begin(); it != tree.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
/*
void maketree(int lev)
{
	if(lev > tree[curchar]) 
	{
		curchar++;
		return;
	}
	
	if(lev < tree[curchar])
	{
		s.push_back('(');
		curchar++;
		maketree(lev+1);
	}
	else if(lev == tree[curchar])
	{
		s.push_back(')');
		s.push_back('(');
		curchar++;
		maketree(lev);
	}
	
	return;
}
*/
int main(int argc, char *argv[]) 
{
	int max = -1;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int j; cin >> j;
		tree.push_back(j);
		if(j > max) max = j;
	}
	
	for(int lev = max; lev >= 1; lev--)
	{
		for(int cur = 0; cur < tree.size(); cur++)
		{
			if(tree[cur] == lev) 
			{
				int foundedindex = -1;
				// find matching node
				for(int curind = cur+1; curind < tree.size(); curind++)
				{
					if(tree[curind] == lev) { foundedindex = curind; break; }
				}
				if(foundedindex == -1) { cout << "no" << endl; return 0; }
				else
				{
					tree.insert(tree.begin() + cur, lev - 1);
					cur = foundedindex+1;
				}
			}
		}
		// printvec();
	}
	
	cout << "yes" << endl;
	
	string s;
	int lastLevel = 0;
	for(int i = 0; i < n-1; i++)
	{
		if(tree[i] < tree[i+1]) s += "(";
		else if(tree[i] == tree[i+1])
		{
			s += "()()";
		}
		else
		{
			for(int j = 0; j < tree[i] - tree[i+1]; j++)
			{
				s += ")";
			}
			s += "(";
		}
		lastLevel = tree[i+1];
	}
	for(int i = 0; i < lastLevel + 1; i++) s += ")";
	cout << s << endl;
}