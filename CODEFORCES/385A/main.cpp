#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int n, c, rasp1, rasp2, answer = 0;
	cin >> n >> c >> rasp1;
	for(int i = 1; i < n; i++){
	        cin >> rasp2;
	        answer = max(answer, rasp1 - rasp2 - c);
	        rasp1 = rasp2;
	    }
	    cout << answer << "\n";
	    return 0;
}