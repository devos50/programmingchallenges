#include <iostream>

using namespace std;

void solve()
{
    int arr[8][4] = {{2,4,8,6},{3,9,7,1},{4,6,4,6},{5,5,5,5},{6,6,6,6},{7,9,3,1},{8,4,2,6},{9,1,9,1}};
    
    int a, b;
    scanf("%d %d", &a, &b);
    if(a > 10) a -= 10;
    if(a == 0 || a == 10) printf("0\n");
    else if(b == 0 || a == 1) printf("1\n");
    else printf("%d\n",arr[a-2][(b-1)%4]);
}
int main(int argc, const char * argv[])
{
int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}

