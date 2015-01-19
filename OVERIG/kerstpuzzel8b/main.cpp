#include <iostream>
#include <set>
#include <vector>

#define NUM_BEATLES 25
#define NUM_STONES 17

using namespace std;

string beatles[] = { "039",
"045",
"076",
"092",
"104",
"126",
"168",
"301",
"308",
"393",
"430",
"441",
"446",
"510",
"594",
"643",
"648",
"653",
"660",
"702",
"825",
"863",
"871",
"874",
"935" };

string rolling_stones[] = { "035",
"046",
"049",
"112",
"196",
"225",
"402",
"627",
"720",
"733",
"737",
"748",
"794",
"812",
"831",
"883",
"970"
};

bool band_cube[6][4] = { {true, true, true, true}, {true, false, true, true}, {false, false, true, false}, {true, true, true, true}, {true, false, true, false}, {true, true, false, true} };

set<int> beatlesUsed;
set<int> stonesUsed;
int solutions = 0;

bool check_edges(vector<vector<string> > s)
{
	set<int> stonesSavedHere;
	set<int> beatlesSavedHere;
	// check B3
	char l1 = s[1][1][1];
	char l2 = s[2][3][1];
	bool canb3 = false;
	for(int i = 0; i < NUM_STONES; i++)
	{
		if(rolling_stones[i][0] == l1 && rolling_stones[i][2] == l2 && stonesUsed.find(i) != stonesUsed.end())
		{
			stonesSavedHere.insert(i);
			canb3 = true;
			break;
		}
	}
	
	// check C3
	l1 = s[2][1][1];
	l2 = s[3][3][1];
	bool canc3 = false;
	for(int i = 0; i < NUM_BEATLES; i++)
	{
		if(beatles[i][0] == l1 && beatles[i][2] == l2 && beatlesUsed.find(i) != beatlesUsed.end())
		{
			beatlesSavedHere.insert(i);
			canc3 = true;
			break;
		}
	}
	
	// check D3
	l1 = s[3][1][1];
	l2 = s[4][3][1];
	bool cand3 = false;
	for(int i = 0; i < NUM_STONES; i++)
	{
		if(rolling_stones[i][0] == l1 && rolling_stones[i][2] == l2 && stonesUsed.find(i) != stonesUsed.end() && stonesSavedHere.find(i) != stonesSavedHere.end())
		{
			stonesSavedHere.insert(i);
			cand3 = true;
			break;
		}
	}
	
	// check C5
	l1 = s[2][2][1];
	l2 = s[5][0][1];
	bool canc5 = false;
	for(int i = 0; i < NUM_STONES; i++)
	{
		if(rolling_stones[i][0] == l1 && rolling_stones[i][2] == l2 && stonesUsed.find(i) != stonesUsed.end() && stonesSavedHere.find(i) != stonesSavedHere.end())
		{
			stonesSavedHere.insert(i);
			canc5 = true;
			break;
		}
	}
	
	// check B5
	l1 = s[1][2][1];
	l2 = s[5][3][1];
	bool canb5 = false;
	for(int i = 0; i < NUM_STONES; i++)
	{
		if(rolling_stones[i][0] == l1 && rolling_stones[i][2] == l2 && stonesUsed.find(i) != stonesUsed.end() && stonesSavedHere.find(i) != stonesSavedHere.end())
		{
			stonesSavedHere.insert(i);
			canb5 = true;
			break;
		}
	}
		
	return canb3 && canc3 && cand3 && canc5;
}

void find(int cube, vector<vector<string> > s, int lvl)
{
	if(lvl == 4 && cube == 5)
	{
		if(!check_edges(s)) { return; }
		
		cout << "SOLUTION:" << endl;
		for(int i = 0; i < 6; i++)
		{
			cout << "cube " << (i + 1) << ": " << endl;
			for(int j = 0; j < s[i].size(); j++)
			{
				cout << "a" << (j + 1) << ": " << s[i][j] << endl;
			}
			cout << endl;
		}
		
		solutions++;
		cout << solutions << endl;
		return;
	}
	else if(lvl == 4)
	{
		find(cube + 1, s, 0); // go to next cube
		return;
	}
	else if(cube == 5 && lvl == 2) // F3
	{
		for(int i = 0; i < 10; i++)
		{
			string num = "";
			num += (char)('0' + i);
			num += '-';
			num += s[cube][1][2];
			s[cube].push_back(num);
			find(cube, s, lvl + 1);
			s[cube].pop_back();
			return;
		}
	}
	
	if(band_cube[cube][lvl])
	{
		// iterate over the Beatles set
		for(int i = 0; i < NUM_BEATLES; i++)
		{
			if(beatlesUsed.find(i) != beatlesUsed.end()) { continue; }
			
			// check if this can be used
			if(lvl > 0)
			{
				if(lvl == 1 && s[cube][0][2] != beatles[i][0]) { continue; }
				if(lvl == 2 && s[cube][1][2] != beatles[i][2]) { continue; }
				if(lvl == 3 && (s[cube][0][0] != beatles[i][0] || s[cube][2][0] != beatles[i][2])) { continue; }
			}
			s[cube].push_back(beatles[i]);
			beatlesUsed.insert(i);
			find(cube, s, lvl + 1);
			s[cube].pop_back();
			beatlesUsed.erase(i);
		}
	}
	else
	{
		// iterate over the Rolling Stones set
		for(int i = 0; i < NUM_STONES; i++)
		{
			if(stonesUsed.find(i) != stonesUsed.end()) { continue; }
						
			// check if this can be used
			if(lvl > 0)
			{
				if(lvl == 1 && s[cube][0][2] != rolling_stones[i][0]) { continue; }
				if(lvl == 2 && s[cube][1][2] != rolling_stones[i][2]) { continue; }
				if(lvl == 3 && (s[cube][0][0] != rolling_stones[i][0] || s[cube][2][0] != rolling_stones[i][2])) { continue; }
			}
			s[cube].push_back(rolling_stones[i]);
			stonesUsed.insert(i);
			find(cube, s, lvl + 1);
			s[cube].pop_back();
			stonesUsed.erase(i);
		}
	}
}

int main(int argc, char *argv[]) 
{
	vector<vector<string> > s;
	for(int i = 0; i < 6; i++) { s.push_back(vector<string>()); }
	find(0, s, 0);
	cout << solutions << endl;
}