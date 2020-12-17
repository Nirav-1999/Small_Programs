#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;

    cin>>T;
    for(int k =0;k<T;k++){
        int n,u,v,count = 0;
        cin>>n;
        vector<vector <int>> arr(n,vector<int> (n,0));
        vector<vector <int>> neighbours(n-1,vector<int> (2,0));
        vector<int> check(n);


        for (int i = 0; i < n; i++)
        {
            cin>>check[i];
        }
        
        for (int i = 0; i < n-1; i++)
        {
            // cout<<i;
            cin>>u>>v;
            arr[u-1][v-1] = 1;
            arr[v-1][u-1] = 1;
            neighbours[i][0] = u-1;
            neighbours[i][1] = v-1;
        }
        
        for (int i = 0; i < n-1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(arr[neighbours[i][1]][j] == 1 && check[neighbours[i][1]] != 1 && j!=neighbours[i][0]){
                    count += 1;
                    check[neighbours[i][1]] = 1;
                    break;
                }
            }
            
        }
        cout<<count<<"\n";
    }
    return 0;
}