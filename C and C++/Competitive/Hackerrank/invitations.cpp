#include<bits/stdc++.h>

using namespace std;

int findMax(int start,int N,vector<int> scores,vector<int> inv,int max,int min){
    
    if(scores[start]<min){
        min = scores[start];
    }

    for (int i = 0; i < N; i++)
    {
            if(inv[i]==start){
            cout<<"findMax("<<i<<","<<max<<","<<min<<")\n";
            max=findMax(i,N,scores,inv,max,min);
            if(max<abs(scores[i] - min)){
                max = abs(scores[i] - min);
                cout<<i<<" ------ "<<scores[i]<<" ------ "<<min<<" ------- "<<max<<"\n";
            }

        }
        
    }
    return max;
    

}

int main(){
    int N,tmp,start,max,min;
    cin>>N;
    vector<int> scores(N),inv(N);
    for (int i = 0; i < N; i++)
    {
        cin>>scores[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin>>tmp;
        if(tmp == -1){
            inv[i] = tmp;
            start = i;
        }
        else
        {
            inv[i] = tmp-1;
        }
        
        
    }
    max = 0;
    min = INFINITY;
    max = findMax(start,N,scores,inv,max,min);
    cout<<max;


    return 0;
}