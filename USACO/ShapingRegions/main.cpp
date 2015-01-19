/*
 ID: mdmarti1
 PROG: rect1
 LANG: C++
 */

#include <iostream>
#include <fstream>

using namespace std;

int colcount[2501], n, W, L;
struct Rectangle
{
    int x1, y1, x2, y2, c;

	Rectangle() { }
	
    Rectangle(int i1,int i2,int i3,int i4)
	{
        x1 = i1; y1 = i2; x2 = i3; y2 = i4; c = 0;
    }
     
} co[1005];
 
int slice(Rectangle a, int i, int n)
{
    int area = (a.x2 - a.x1) * (a.y2 - a.y1);
    if(area <= 0 || a.x2 < a.x1 || a.y2 < a.y1) 
        return 0;
    if(n == i) return area;
    Rectangle b = co[n];
    if(b.x1 > a.x2 || b.x2 < a.x1 || b.y1 > a.y2 || b.y2 < a.y1)
        return slice(a, i, n - 1);
    int t = slice(Rectangle(a.x1, a.y1, b.x1, a.y2), i, n - 1);
    t += slice(Rectangle(b.x2, a.y1, a.x2, a.y2), i, n - 1);
    t += slice(Rectangle(max(a.x1, b.x1), b.y2, min(a.x2, b.x2), a.y2), i, n - 1);        
    t += slice(Rectangle(max(a.x1, b.x1), a.y1, min(a.x2, b.x2), b.y1), i, n - 1);        
    
	return t;
}
int main()
{
    ifstream cin("rect1.in");
    ofstream cout("rect1.out");
    cin >> W >> L >> n;
    co[0].x2 = W; co[0].y2 = L; co[0].c = 1;  
    for(int i = 1; i <= n; i++)
        cin >> co[i].x1 >> co[i].y1 >> co[i].x2 >> co[i].y2 >> co[i].c;
    for(int cs = n; cs >= 0; cs--)
        colcount[co[cs].c] += slice(co[cs], cs, n);
    for(int i = 1; i <= 2500; i++) 
        if(colcount[i])
            cout << i << " " <<colcount[i] << endl;
    return 0;
}