#include<stdio.h>

#define N 5
int distance[N];
int edge[20][2];

int bellmanford(int G[N][N], int src,int num_edges){
    int parent[N],i,j,u,v,flag=1;
    for(i = 0; i < N; i++)
    {
        parent[i]=-1;
        distance[i]=999;
    }
    distance[src-1]=0;
    for(i=0;i<N-1;i++){
        for(j=0;j<num_edges;j++){
            u = edge[j][0];
            v = edge[j][1];
            if(distance[u] + G[u][v] < distance[v]){
                distance[v] = distance[u] + G[u][v];
                parent[v] = u;
            }
        }
    }
    for(j=0;j<num_edges;j++){
        u = edge[j][0];
        v = edge[j][1];
        if(distance[u] + G[u][v] < distance[v]){
            flag = 0;
        }
    }
    if(flag){
        for( i = 0; i < N; i++)
        {
            printf("Vertex %d -> cost =%d, parent = %d\n",i+1,distance[i],parent[i]+1);
        }
        
    }
    return flag;
}

void main(){
    int i,j,k=0;
    int a[N][N] = 
      {{0,6,0,7,0}, 
       {0,0,5,8,-4}, 
       {0,-2,0,0,0}, 
       {0,0,-3,0,9}, 
       {2,0,7,0,0}}; 
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(a[i][j]!=0){
                edge[k][0]=i;
                edge[k++][1]=j;
            }
        }
        
        
    }
    
    int source = 1;
    if(bellmanford(a,source,k)){
        printf("No negative weight cycles");
    }
    else
    {
        printf("Negative weight cycle exists");
    }
    

}