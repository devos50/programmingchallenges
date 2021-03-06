#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<int> KMP(string S, string K)
{
        vector<int> T(K.size() + 1, -1);
        vector<int> matches;
 
        if(K.size() == 0)
        {
            matches.push_back(0);
            return matches;
        }
        for(int i = 1; i <= K.size(); i++)
        {
                int pos = T[i - 1];
                while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
                T[i] = pos + 1;
        }
 
        int sp = 0;
        int kp = 0;
        while(sp < S.size())
        {
                while(kp != -1 && (kp == K.size() || K[kp] != S[sp])) kp = T[kp];
                kp++;
                sp++;
                if(kp == K.size()) matches.push_back(sp - K.size());
        }
 
        return matches;
}

int main(int argc, char *argv[]) 
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		string text, pattern;
		cin >> pattern >> text;
		vector<int> matches = KMP(text, pattern);
		
		for(vector<int>::iterator it = matches.begin(); it != matches.end(); it++) cout << *it << endl;
		cout << endl;
	}
}