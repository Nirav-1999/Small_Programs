#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>

using namespace std;

bool sortcol( const vector<float>& v1, const vector<float>& v2 ) { 
    return v1[3] > v2[3]; 
}

int main(){
    int T,temp;
    cin>>T;
    temp = T;
    while(T--){
        int n,E=0,S,L;
        float in,max=0;
        cin>>n;
        vector<vector<float> > arr;
        for(int i=0;i<n;i++){
            vector<float> temp;
            for(int j=0;j<3;j++){
                cin>>in;
                temp.push_back(in);
                if(j==2){
                    temp.push_back(temp[1]/temp[0]);
                }
            }
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end(),sortcol); 
        for(int i=0;i<n;i++){
            for(int j=0;j<4;j++){
                cout<<arr[i][j]<<"\t";
            }
            cout<<"\n";
        }

        cout<<"hi";

        for (int j = 0; j < n; j++){
            int tempo;
            if(arr[j][2] == 0){
                int index = j, final_cond = n;
                while(arr[index][2]==0 && final_cond>0){
                    cout<<arr[index][2];
                    index++;
                    final_cond--;
                }
                cout<<"hi";
                if(final_cond!=0){
                    for(int i = 0; i < 4 ; i++){
                        tempo = arr[index][i];
                        arr[index][i] = arr[index+1][i];
                        arr[index+1][i] = tempo;
                    }
                }
            }
            E += arr[max][1];
            // cout<<E<<"===="<<arr[max][1]<<"\n";
            S = arr[max][0];
            max = j+1;
            for (int k = j+1; k < n; k++)
            {
                
                arr[k][1] -= (S * arr[k][2]);
                
                if(arr[k][1]<0){
                    arr[k][1]=0;
                }
                arr[k][3] = arr[k][1]/arr[k][0];
            }
            for (int k = j+1; k < n-1; k++)
            {
                if(arr[max][3]<arr[k+1][3]){
                    max = k+1;
                }
            }
            
            // cout<<"max = "<<max<<"\n";
            // cout<<"Table\n";
            // cout<<arr[0][0]<<"\t"<<arr[0][1]<<"\t"<<arr[0][2]<<"\t"<<arr[0][3]<<"\n";
            // cout<<arr[1][0]<<"\t"<<arr[1][1]<<"\t"<<arr[1][2]<<"\t"<<arr[1][3]<<"\n";
            // cout<<arr[2][0]<<"\t"<<arr[2][1]<<"\t"<<arr[2][2]<<"\t"<<arr[2][3]<<"\n";
            // cout<<arr[3][0]<<"\t"<<arr[3][1]<<"\t"<<arr[3][2]<<"\t"<<arr[3][3]<<"\n";
            
        }
        cout<<"Case #"<<temp-T<<": "<<E<<"\n";
        
    }
    return 0;
}