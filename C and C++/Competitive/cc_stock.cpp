#include<bits/stdc++.h>

using namespace std;

int check_cond(long long int a1,long long int a2,long long int b1,long long int b2){
    if(a1<a2){
        if(b1<b2){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(a2<a1){
        if(b2<b1){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(a1==a2){
        return 1;
    }
}

int main(){
    int T,count;
    int N;
    cin>>T;
    for (int i = 0; i < T; i++)
    {
        cin>>N;
        vector<vector <long long int>> stocks(N,vector<long long int> (2));
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cin>>stocks[j][k];
            }
            
        }
        // for (int j = 0; j < N; j++)
        // {
        //     for (int k = 0; k < 2; k++)
        //     {
        //         cout<<stocks[j][k]<<"\t";
        //     }
        //     cout<<"\n";
        // }
        // vector<vector <long long int>> dynamic_stocks(N-1);
        int max = 0;
        // vector <long long int> temp;
        // temp.push_back(0);

        // dynamic_stocks.push_back(temp);
        for (int j = 0; j < N; j++)
        {
            count = 0;
            // vector <long long int> temp;
            for (int k = 0; k < j; k++)
            {   
                if(check_cond(stocks[k][0],stocks[j][0],stocks[k][1],stocks[j][1])){
                    count++;
                }
                // temp.push_back(count);
                if(max<count){
                    max = count;
                }
                
            }
            // dynamic_stocks.push_back(temp);
            
        }
        cout << max+1;
        
    }
    
    



    return 0;
}