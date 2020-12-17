#include<bits/stdc++.h>

using namespace std;

int main(){

    int T;
    cin>>T;

    for (int c = 0; c < T; c++)
    {
        int N,K,flag = 0 ;
        cin>>N>>K;
        
        vector<int> permutations(N+1);
        vector<int> done(N+1,0);
        vector<vector <int>> steps;


        for (int i = 1; i <= N; i++)
        {
            cin>>permutations[i];
        }
        
        int index = 1,count = 0,not_visited = N,visited = 0;

        while(index < N){
            // for (int j = 1; j <= permutations.size(); j++){
            //         cout << permutations[j] << "\t"; 
            // }
            if(permutations[permutations[index]] != permutations[index]){
                int p1,p2,p3;
                p1 = index;
                p2 = permutations[index];

                if(abs(permutations[index] - index) == 1 ){
                    p3 = p2 + 1;
                    while( done[p3] != 0 && p3 < N+1 ){
                        p3++;
                    }
                    
                }
                else{
                    p3 = p2 + 1;
                    while( done[p3] != 0 && p3 < N+1 ){
                        p3++;
                    }
                    if(p3 == N+1){
                        p3 = p1+1;
                        while (done[p3] != 0 && p3<p2)
                        {
                            p3++;
                        }
                        
                    }
                    if(p3 == p2){
                        flag = 1;
                        break;
                    }
                    
                }
                
                while (permutations[permutations[index]] != permutations[index])
                {
                    int temp;
                    vector<int> t;
                    t.push_back(p1);
                    t.push_back(p2);
                    t.push_back(p3);
                    steps.push_back(t);
                    temp = permutations[p1];
                    permutations[p1] = permutations[p3];
                    permutations[p3] = permutations[p2];
                    permutations[p2] = temp;
                    count += 1;
                    if(count > K){
                        flag = 1;
                        break;
                    }

                }
                done[permutations[index]] = 1;
                

            }
            else
            {
                done[index] = 1;
                index += 1;
            }
            
            
            
            

            
            




        }
        if(flag==1){
            cout<<-1<<"\n";
            // for (int i = 0; i < steps.size(); i++) { 
            //     for (int j = 0; j < steps[i].size(); j++){
            //         cout << steps[i][j] << "\t"; 
            //     }
            //     cout<<"\n";
            // }
          
            
        }
        else{
            cout<<count<<"\n";
            for (int i = 0; i < steps.size(); i++) { 
                for (int j = 0; j < steps[i].size(); j++){ 
                    cout << steps[i][j] << " "; 
                }
            cout<<"\n";
            }
        }

    }
    




    return 0;
}