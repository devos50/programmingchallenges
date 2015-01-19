#include <iostream>
#include <list>
#include <cstring>

using namespace std;

void solve()
{
	string commands; cin >> commands;
	int l; cin >> l;
	string slist; cin >> slist;
	slist = slist.substr(1, slist.size() - 2);
	list<string> thelist;
	int listsize = 0;
	
	char *pch;
	pch = strtok(&slist[0], ",");
	while(pch != NULL)
	{
		thelist.push_back(pch);
		listsize++;
		pch = strtok(NULL, ",");
	}
	
	bool rev = false;
	
	for(int i = 0; i < commands.size(); i++)
	{
		char cmd = commands.at(i);
		if(cmd == 'R')
			rev = !rev;
		else if(cmd == 'D')
		{
			if(listsize == 0)
			{
				cout << "error" << endl;
				return;
			}
			if(rev) thelist.pop_back();
			else thelist.pop_front();
			listsize--;
		}
	}
	cout << "[";
	
	if(rev) thelist.reverse();
	
	int index = 0;
	for(list<string>::iterator it = thelist.begin(); it != thelist.end(); it++)
	{
		if(index == listsize-1) cout << *it;
		else cout << *it << ",";
		index++;
	}
	cout << "]" << endl;
}

int main(int argc, char *argv[]) 
{
	int t; cin >> t;
	while(t--) solve();
}