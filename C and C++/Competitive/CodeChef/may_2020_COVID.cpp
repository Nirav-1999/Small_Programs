#include<bits/stdc++.h>

using namespace std;


int main(){
    int T;

    cin>>T;

    for (int case_num = 0; case_num < T; case_num++)
    {
        int N,flag = 0,min_int,max_int,min,max;

        cin>>N;
        vector<int> pos(N);

        
        for (int i = 0; i < N; i++)
        {
            cin>>pos[i];
        }

        min = 1;
        max = 1;

        for (int i = 0; i < N-1; i++)
        {
            if(pos[i+1] - pos[i] <= 2){
                min++;
                max++;
                
            }
            else{
                if(flag == 0){
                    min_int = min;
                    max_int = max;
                    flag = 1;
                    
                }
                else{
                    if(max_int < max){
                        max_int = max;
                    }
                    if(min_int > min){
                        min_int = min;
                    }
                }
                min = 1;
                max = 1;
                
            }
            if(i == N-2){
                if(flag == 0){
                    min_int = min;
                    max_int = max;
                    flag = 1;
                    
                }
                else{
                    if(max_int < max){
                        max_int = max;
                    }
                    if(min_int > min){
                        min_int = min;
                    }
                }
            }
            // std :: cout<<"Always "<<min_int<<" ---- "<<max_int<<"\n";
            

        }
        std :: cout<<min_int<<" "<<max_int<<"\n";
        
        
    }
    





    return 0;
}