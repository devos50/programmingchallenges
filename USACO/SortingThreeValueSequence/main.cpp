/*
 ID: mdmarti1
 PROG: sort3
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");

	int n; fin >> n;
	int data[n];
	int swaps = 0;
	for(int i = 0; i < n; i++) fin >> data[i];
	
	// tel aantal 1's, 2's en 3's
	int freq[4]; for(int i = 0; i < 4; i++) freq[i] = 0;
	for(int i = 0; i < n; i++) freq[data[i]]++;
	
	// tel aantal tweeeen in het eerste gedeelte
	int p = 0;
	for(int i = 0; i < freq[1]; i++)
		if(data[i] == 2) p++;
	
	// vervang alle tweeeen in het eerste gedeelte door enen
	for(int i = freq[1]; i < n && p > 0; i++)
	{
		if(data[i] == 1) // vervang deze 1 met de meest linkse 2
		{
			// zoek de meest linkse twee
			int ind = 0;
			bool found = false;
			for(int j = 0; j < freq[1] && !found; j++)
			{
				if(data[j] == 2)
				{
					ind = j;
					found = true;
				}
			}
			
			// swap
			swap(data[i], data[ind]);
			swaps++;
			p--;
		}
	}
	
	// zet de laatste enen op z'n plek
	for(int i = freq[1]; i < n; i++)
	{
		if(data[i] == 1)
		{
			// zoek de meest linkse twee
			int ind = 0;
			bool found = false;
			
			while(data[ind] == 1)
				ind++;
						
			// swap
			swap(data[i], data[ind]);
			swaps++;
			p--;
		}
	}
	
	// het aantal swaps dat we nu nog nodig hebben, is het aantal foute getallen in het gedeelte met de tweeeen
	for(int i = freq[1]; i < freq[1] + freq[2]; i++)
		if(data[i] != 2) swaps++;
	
	cout << "new array: ";
	for(int i = 0; i < n; i++) cout << data[i] << " ";
	cout << endl;
	
	fout << swaps << endl;
	
    return 0;
}