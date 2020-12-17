    #include<bits/stdc++.h>


    using namespace std;

    int main(){
        int T;
        cin>>T;
        
        for (int c = 0; c < T; c++)
        {
            int N;
            cin>>N;

            vector<int> days(N);

            for (int i = 0; i < N; i++)
            {
                cin>>days[i];
            }


            int max = 0,count = 0;

            for (int i = 0; i < N; i++)
            {
                if(i == 0){
                    if(days[i] > days[i+1]){
                        count++;
                    }
                
                }
                else if(i == N-1){
                    if(days[i]>max){
                        count++;
                    }
                } 
                else{
                    if((days[i] > days[i+1]) && (days[i] > max)){
                        count++;
                    }
                }
                if(days[i] > max){
                    max = days[i];
                }
                // cout<<"days[i] : "<<days[i]<<"\n";
                // cout<<"days[i+1] : "<<days[i+1]<<"\n";
                // cout<<"max : "<<max<<"\n";
                // cout<<"count : "<<count<<"\n";




            }
            
            cout<<"Case #"<<c+1<<": "<<count<<"\n";
            
            
        }





        return 0;
    }