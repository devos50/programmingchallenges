//
//  main.cpp
//  labyr1
//
//  Created by M.A. de Vos on 22-11-12.
//  Copyright (c) 2012 M.A. de Vos. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
#include <cstdlib>

using namespace std;

int width, height;
char labyrinth[1005][1005];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int maxcode;

int seen[1005*1005];

int bfs(int start)
{
    int maxsteps = 0;
    queue<int> q;
    for(int y = 0; y < height; y++) for(int x = 0; x < width; x++) seen[x * 1005 + y] = -1;
    q.push(start);
    seen[start] = 0;
    while(!q.empty())
    {
        int code = q.front();
        q.pop();
        
        int steps = seen[code];
        int y = code % 1005; code /= 1005;
        int x = code;
        
        for(int i = 0; i < 4; i++)
        {
            int newX = x + dx[i], newY = y + dy[i];
            if(newX >= 0 && newX < width && newY >= 0 && newY < height && labyrinth[newY][newX] != '#')
            {
                int newcode = newX * 1005 + newY;
                if(seen[newcode] == -1)
                {
                    seen[newcode] = steps + 1;
                    if(steps + 1 > maxsteps) { maxsteps = steps + 1; maxcode = newcode; }
                    q.push(newcode);
                }
            }
        }
    }
    return maxsteps;
}

void solve()
{
    scanf("%d %d", &width, &height);
    int start = 0;
    bool startFound = false;
    
    for(int y = 0; y < height; y++)
    {
        scanf("%s", labyrinth[y]);
        for(int x = 0; x < width; x++)
            if(!startFound && labyrinth[y][x] == '.') { start = x * 1005 + y; startFound = true; }
    }
    
    if(!startFound)
    {
        printf("Maximum rope length is 0.\n");
        return;
    }
    
    bfs(start);
    printf("Maximum rope length is %d.\n", bfs(maxcode));
}

int main(int argc, const char * argv[])
{
    int t;
    scanf("%d", &t);
    while(t--) solve();
    
    return 0;
}

