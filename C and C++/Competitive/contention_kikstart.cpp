#include<iostream>
#include<math.h>
#include<string.h>
#include<bits/stdc++.h>

using namespace std;

struct Seats{
    int left,right,total_count=0,rem_count=0;
    bool operator() (Seats i,Seats j){
        return (i.total_count>j.total_count);
    }
}seat_func;

int main(){
    
    int T;
    cin>>T;
    for (int iterations = 0; iterations < T; iterations++)
    {
        vector<Seats> seats;
        int flag=0;
        int N,Q,min_item;
        cin>>N>>Q;
        vector<int> result(N,-1);
        for(int i =1;i<=Q;i++){
            struct Seats s1;
            cin>>s1.left>>s1.right;
            s1.total_count = s1.right - s1.left+1;
            seats.push_back(s1);
        }
        sort(seats.begin(),seats.end(),seat_func);
        // for (int j = 0; j < Q; j++)
        // {
            // cout<<seats[j].left<<" "<<seats[j].right<<" - "<<seats[j].total_count<<"\n";
        // }

        // cout<<"++++++++++++++++++++++++++++++++++++\n";
        for(int i=0;i<Q;i++){
            // cout<<"*********************************\n";
            // cout<<"Outer for\n";
            for(int j=seats[i].left-1;j<seats[i].right;j++){
                // cout<<"Iner For\n";
                if(result[j]!=-1){
                    seats[result[j]].total_count--;
                }
                
                result[j] = i;
                seats[i].rem_count++;
                if(seats[result[j]].total_count==1){
                    if(seats[i].rem_count==0){
                        flag = 1;
                    }
                    break;
                }

            }
            if(flag==1){
                break;
            }
            // for (int l = 0; l < N; l++)
            // {
                // cout<<result[l]<<" ---- "<<seats[result[l]].rem_count<<" ---- "<<seats[result[l]].total_count<<"\n";
            // }
            // cout<<"*********************************\n";

        }
        min_item = INFINITY;
        for(int i=0;i<Q;i++){
            if(seats[i].total_count<min_item){
                min_item = seats[i].total_count;
            }
        }
        
        cout<<"Case #"<<iterations+1<<": "<<min_item<<"\n";
        // cout<<"=============FinalReult==================\n";
        // for (int j = 0; j < N; j++)
        // {
            // cout<<result[j]<<"\n";
        // }
        // cout<<"=========================================\n";
        
    }
    
    

    return 0;
}