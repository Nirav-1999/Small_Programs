#include<bits/stdc++.h>

using namespace std;


int main(){
    int T;
    cin>>T;

    for (int c = 0; c < T; c++)
    {
        int N,K;
        cin>>N>>K;
        vector<long long int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin>>A[i];
        }
        int i = 0,count = 0;
        while(i<=N-K+1)
        {
            cout<<"I = "<<i<<"\n";
            if(A[i] == K){
                int flag = 0;

                int j=i;
                int temp = K;
                while(j<i+K){
                    if(A[j] != K){
                        flag = 1;
                        break;
                    }
                    j+=1;
                    temp -= 1;
                }
                if(flag == 0){
                    count+=1;
                    i += K - 1;
                }
            }
            
            
            
                i+=1;
            
            cout<<count<<"\n";

                
            
        }
        cout<<"Case #"<<c+1<<": "<<count<<"\n";
        
        
    }
    





    return 0;
}