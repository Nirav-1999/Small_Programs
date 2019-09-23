#include<stdio.h>

#define N 8
int cost[N];

int min(int a,int b){
    return (a<b)?a:b;
}

void multistage(int G[N][N]){
    int i,j;
    cost[N-1] = 0;
    for(i=N-2;i>=0;i--){
        cost[i] = 999;
        for(j = i; j < N; j++)
        {
            if(G[i][j] == 999){
                continue;
            }
            cost[i] = min(cost[i],G[i][j] + cost[j]);
        }
        
    }
    printf("%d\n",cost[0]);
}

void main(){
    int a[N][N] = 
      {{999, 1, 2, 5, 999, 999, 999, 999}, 
       {999, 999, 999, 999, 4, 11, 999, 999}, 
       {999, 999, 999, 999, 9, 5, 16, 999}, 
       {999, 999, 999, 999, 999, 999, 2, 999}, 
       {999, 999, 999, 999, 999, 999, 999, 18}, 
       {999, 999, 999, 999, 999, 999, 999, 13}, 
       {999, 999, 999, 999, 999, 999, 999, 2}}; 

    multistage(a);

}