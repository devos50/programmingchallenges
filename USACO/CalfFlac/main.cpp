/*
 ID: mdmarti1
 PROG: calfflac
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string text;
char stripped[20005];
int indices[20005];
int strippedindex;

int main()
{
    ofstream fout ("calfflac.out");
    ifstream fin ("calfflac.in");
    while(!fin.eof())
    {
        string part;
        getline(fin, part);
        text.append(part + '\n');
    }
    
    cout << "text: " << text << endl << endl;
    
    // strip whitespaces etc...
    // string stripped = "";
    strippedindex = 0;
    for(int i = 0; i < text.length(); i++)
    {
        char c = text.at(i);
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            if(c >= 'A' && c <= 'Z') c = (char)(c + 32);
            stripped[strippedindex] = c;
            indices[strippedindex] = i;
            strippedindex++;
        }
    }
    
    // check palindromes in text
    int seqLen = strippedindex;
    int lLen = 2 * seqLen + 1;
    int l[lLen];
    for(int i = 0; i < lLen; i++)
    {
        int s = i / 2;
        int e = s + i % 2;
        int c = 0;
        
        while(c <= 1001 && s > 0 && e < seqLen && stripped[s - 1] == stripped[e])
        {
            s -= 1;
            e += 1;
            c++;
        }
        l[i] = e - s;
    }
    
    for(int i = 0; i < lLen - 1; i++) cout << l[i] << " ";
    cout << endl;
    
    int max = -1;
    int index = -1;
    for(int i = 0; i < lLen - 1; i++)
        if(l[i] > max) { max = l[i]; index = i; }
    
    int beginindex = 0, endindex = 0;
    if(index % 2 == 0)
    {
        beginindex = indices[index / 2 - max / 2];
        endindex = indices[index / 2 + max / 2 - 1];
    }
    else
    {
        beginindex = indices[index / 2 - max / 2];
        endindex = indices[index / 2 + max / 2];
    }
    
    cout << "begin: " << beginindex << ", end: " << endindex << endl;
    fout << max << endl;
    for(int i = beginindex; i <= endindex; i++) fout << text.at(i);
    fout << endl;
    return 0;
}