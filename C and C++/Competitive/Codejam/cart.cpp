// There are a lot of great streetside food vendors in Manhattan, but without a doubt, the one with the tastiest food is the Code Jam Crepe Cart!

// You want to find the cart, but you do not know where it is, except that it is at some street intersection. 
// You believe that people from across Manhattan are currently walking toward that intersection, so you will try to identify the intersection toward which the most people are traveling.

// For the purposes of this problem, Manhattan is a regular grid with its axes aligned to compass lines and bounded between 0 and Q, inclusive, on each axis. 
// There are west-east streets corresponding to gridlines y = 0, y = 1, y = 2, …, y = Q and south-north streets corresponding to gridlines x = 0, x = 1, x = 2, …, x = Q, and people move only along these streets. 
// The points where the lines meet — e.g., (0, 0) and (1, 2) — are intersections. 
// The shortest distance between two intersections is measured via the Manhattan distance — that is, by the sum of the absolute horizontal difference and the absolute vertical difference between the two sets of coordinates.

// You know the locations of P people, all of whom are standing at intersections, and the compass direction each person is headed: 
// north (increasing y direction), south (decreasing y direction), east (increasing x direction), or west (decreasing x direction). 
// A person is moving toward a street intersection if their current movement is on a shortest path to that street intersection within the Manhattan grid. 
// For example, if a person located at (x0, y0) is moving north, then they are moving toward all street intersections that have coordinates (x, y) with y > y0.

// You think the crepe cart is at the intersection toward which the most people are traveling.
//  Moreover, you believe that more southern and western parts of the island are most likely to have a crepe cart, 
//  so if there are multiple such intersections, you will choose the one with the smallest non-negative x coordinate, 
//  and if there are multiple such intersections with that same x coordinate, the one among those with the smallest non-negative y coordinate. 
//  Which intersection will you choose?

#include<iostream>

using namespace std;

struct people{
    char dir[10];
    int x,y;
}P[10];

int main(){
    int g[50][50] = {0},p,q,max=0,x,y,T;
    cin>>T;
    for (int k = 0; k < T; k++)
    {
        int g[50][50] = {0};
        cin >> p >> q;
        for (int i = 0; i < p; i++)
        {
            cin>>P[i].x>>P[i].y>>P[i].dir[0];
        }
        for (int i = 0; i < p; i++)
        {
            if(P[i].dir[0] == 'N'){
                for (int k = 0; k < q; k++)
                {
                    for (int j = P[i].y; j <= q; j++)
                    {
                        if(P[i].y == j){
                            continue;
                        }
                        g[k][j]++;
                        if(max < g[k][j]){
                            max = g[k][j];
                            x = k;
                            y = j;
                        }
                        
                    }
                }
                

                
            }

            else if(P[i].dir[0] == 'S'){
                for (int k = 0; k < q; k++)
                {
                    for (int j = 0; j <= P[i].y; j++){
                        if(P[i].y == j){
                            continue;
                        }
                        g[k][j]++;
                        if(max < g[k][j]){
                            max = g[k][j];
                            x = k;
                            y = j;
                        }
                    }
                }
                
                
                
            }
            else if(P[i].dir[0] == 'E'){
                for (int k = 0; k < q; k++){
                    for (int j = P[i].x; j <= q; j++){
                        if(P[i].x == j){
                            continue;
                        }
                        g[j][k]++;
                        if(max < g[j][k]){
                            max = g[j][k];
                            x = j;
                            y = k;
                        }
                }
                }
                
                
                
            }
            else if(P[i].dir[0] == 'W'){
                for (int k = 0; k < q; k++){
                    for (int j = 0; j <= P[i].x; j++){
                        if(P[i].x == j){
                            continue;
                        }
                        g[j][k]++;
                        if(max < g[j][k]){
                            max = g[j][k];
                            x = j;
                            y = k;
                        }
                    }
                }
                
                
                
            }
        }

        cout<<"Case #"<<k+1<<": "<<x<<" "<<y<<"\n";
    }
    
    

    return 0;
}