#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Problem {
	int contestant;
	int problemId;
	int incorrectSubmissions;
	bool hasCorrect;
	int correctSubmissionTime;
} Problem;

typedef struct TeamInfo {
	int contestant;
	int problemsSolved;
	int timePenalty;
	
	bool operator<(const TeamInfo &a) const
	{
		if(problemsSolved > a.problemsSolved) return true;
		else if(problemsSolved < a.problemsSolved) return false;
		else
		{
			if(timePenalty < a.timePenalty) return true;
			else if(timePenalty > a.timePenalty) return false;
			else return contestant < a.contestant;
		}
	}
} TeamInfo;

map<pair<int, int>, Problem> problems;

void solve(int case_num)
{
	// cout << "NEW TEST CASE" << endl;
	problems.clear();
	bool hasSubmission[105]; for(int i = 0; i < 105; i++) hasSubmission[i] = false;
	
	string s;
	while(true)
	{
		getline(cin, s);
		// cout << "string zero: " << (int)s.at(0) << endl;
		if((int)s[0] == 13 || s.size() == 0) { break; }
		
		stringstream ss; ss << s;
		string buf;
		
		// cout << "STRING: " << s << endl;
		
		ss >> buf;
		int contestant = atoi(buf.c_str());
		ss >> buf;
		int problem = atoi(buf.c_str());
		ss >> buf;
		int time = atoi(buf.c_str());
		ss >> buf;
		char code = buf[0];
		
		hasSubmission[contestant] = true;
		
		if(code == 'R' || code == 'U' || code == 'E') continue;
		
		if(problems.find(make_pair(contestant, problem)) == problems.end()) // new
		{
			// cout << "c: " << contestant << ", p: " << problem << ", code: " << code << endl;
			Problem p;
			p.incorrectSubmissions = 0, p.hasCorrect = false, p.correctSubmissionTime = 0;
			p.contestant = contestant, p.problemId = problem;
			if(code == 'C') { p.correctSubmissionTime = time; p.hasCorrect = true; }
			else if(code == 'I') { p.incorrectSubmissions++; }
			problems[make_pair(contestant, problem)] = p;
		}
		else
		{
			Problem p = problems[make_pair(contestant, problem)];
			if(p.hasCorrect) continue;
			
			if(code == 'C') { p.hasCorrect = true; p.correctSubmissionTime = time; }
			else if(code == 'I') { p.incorrectSubmissions++; }
			problems[make_pair(contestant, problem)] = p;
		}
	}
	
	// find the answer ...
	int problemsSolved[105], timePenalty[105];
	for(int i = 0; i < 105; i++) problemsSolved[i] = 0, timePenalty[i] = 0;
	
	for(map<pair<int, int>, Problem>::iterator it = problems.begin(); it != problems.end(); it++)
	{
		// cout << "iterating over " << it->second.contestant << ", " << it->second.problemId << "correct: " << it->second.hasCorrect << endl;
		int contestant = it->second.contestant;
		int problem = it->second.problemId;
		if(it->second.hasCorrect)
		{
			problemsSolved[contestant]++;
			timePenalty[contestant] += it->second.correctSubmissionTime + 20 * it->second.incorrectSubmissions;
		}
	}
	
	vector<TeamInfo> ti_vec;
	for(int i = 1; i <= 100; i++)
	{
		if(!hasSubmission[i]) continue;
		TeamInfo ti; ti.contestant = i;
		ti.problemsSolved = problemsSolved[i];
		ti.timePenalty = timePenalty[i];
		ti_vec.push_back(ti);
	}
	
	sort(ti_vec.begin(), ti_vec.end());
	for(vector<TeamInfo>::iterator it = ti_vec.begin(); it != ti_vec.end(); it++)
	{
		cout << it->contestant << " " << it->problemsSolved << " " << it->timePenalty << endl;
	}
	if(case_num != 0) cout << endl;
}

int main(int argc, char *argv[]) 
{
	int n; cin >> n;
	string s;
	getline(cin, s); getline(cin, s);
	for(int i = n - 1; i >= 0; i--) solve(i);
}