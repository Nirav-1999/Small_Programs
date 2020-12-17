#include<bits/stdc++.h>


using namespace std;

int main(){
    int T;
    cin>>T;
    
    for (int c = 0; c < T; c++)
    {
        long long int N;
        cin>>N;

        vector<long long int> pitch(N);

        for (int i = 0; i < N; i++)
        {
            cin>>pitch[i];
        }

        int count = 0,breaks = 0,max_allowed = 0,min_allowed = 0;

        for (long long int i = 0; i < N - 1; i++)
        {
            if(pitch[i] > pitch[i+1]){
                count--;
                min_allowed = min(min_allowed,count);
            }
            else if(pitch[i] < pitch[i+1]){
                count++;
                max_allowed = max(max_allowed,count);
            }
            if(max_allowed - min_allowed >= 4){
                breaks++;
                count = 0;
                max_allowed = 0;
                min_allowed = 0;
            }
            // cout<<pitch[i]<<" - "<<breaks<<" - "<<count<<"\n";
        }
        cout<<"Case #"<<c+1<<": "<<breaks<<"\n";
        
        
    }





    return 0;
}