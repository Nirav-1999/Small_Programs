#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>

using namespace std;

int findMax(vector<vector<float> > arr, int n){
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i][3]>arr[max][3]){
            max = i;
        }
        else if (arr[i][3] == arr[max][3])
        {
            if(arr[i][2] > arr[max][2]){
                max = i;
            }
        }
        // cout<<"================="<<max;

    }
    

    return max;
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
        
        for(int i=0;i<n;i++){
            for(int j=0;j<4;j++){
                cout<<arr[i][j]<<"\t";
            }
            cout<<"\n";
        }
        
        
        for (int j = 0; j < n; j++){
            max = findMax(arr,n);
            int tempo;
            E += arr[max][1];
            // cout<<E<<"===="<<arr[max][1]<<"\n";
            S = arr[max][0];
            arr[max][1] = 0;
            arr[max][3] = 0;
        
            if(arr[max][2] == 0){
                continue;
            }
            for (int k = 0; k < n; k++)
            {
                if(k == max){
                    continue;
                }
                arr[k][1] -= (S * arr[k][2]);
                
                if(arr[k][1]<0){
                    arr[k][1]=0;
                }
                arr[k][3] = arr[k][1]/arr[k][0];
            }
            
            
            cout<<"\nmax = "<<max<<"\n";
            cout<<"Table\n";
            cout<<arr[0][0]<<"\t"<<arr[0][1]<<"\t"<<arr[0][2]<<"\t"<<arr[0][3]<<"\n";
            cout<<arr[1][0]<<"\t"<<arr[1][1]<<"\t"<<arr[1][2]<<"\t"<<arr[1][3]<<"\n";
            cout<<arr[2][0]<<"\t"<<arr[2][1]<<"\t"<<arr[2][2]<<"\t"<<arr[2][3]<<"\n";
            cout<<arr[3][0]<<"\t"<<arr[3][1]<<"\t"<<arr[3][2]<<"\t"<<arr[3][3]<<"\n";
            
        }
        cout<<"Case #"<<temp-T<<": "<<E<<"\n";
        
    }
    return 0;
}