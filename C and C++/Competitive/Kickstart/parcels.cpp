#include<iostream>
#include<vector>
#include<math.h>
#include<string.h>
// #include<bits/stdc++.h>

using namespace std;

int distance(int x1,int y1,int x2,int y2){
    return abs(x2-x1)+abs(y2-y1);
}



int main(){
    int T;
    cin>>T;
    for (int p = 0; p < T; p++)
    {
        int r,c,x,pt_offices=0,no_offices=0,dist,flag,max=0,pos_x=-1,pos_y=-1,res_max=0;
        vector<vector<int>> arr;
        vector<vector<int>> result;
        vector<vector<int>> offices;
        string str;

        cin>>r>>c;
        cin.ignore(256, '\n');
        for (int i = 0; i < r; i++)
        {   
            getline(cin,str);
            // cout<<str;
            vector<int> temp;
            for (int j = 0; j < c; j++)
            {
                vector<int> temp_offices;
                x = (int)(str[j]-'0');
                // cout<<"--->"<<str[j]<<"---->"<<x<<"\n";
                temp.push_back(x);
                if(x==1){
                    
                    // cout<<"**"<<i<<"**"<<j<<"\n";
                    temp_offices.push_back(i);
                    temp_offices.push_back(j);
                    // cout<<temp_offices[0]<<"&&&&"<<temp_offices[1]<<"\n";
                    offices.push_back(temp_offices);
                    // cout<<offices[no_offices][0]<<"^^^^"<<offices[no_offices][1]<<"\n";
                    no_offices++;

                }
            }
            arr.push_back(temp);
            result.push_back(temp);
            // cout<<"Success\n";
            
        }
        
        // for (int i = 0; i < no_offices; i++)
        // {
        //     for (int j = 0; j < 2; j++)
        //     {
        //         cout << offices[i][j];
        //     }
        //     cout<<"\n";
            
        // }
        

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                flag=0;
                // cout<<"Doing\n";
                if(i==offices[pt_offices][0] && j==offices[pt_offices][1]){
                    pt_offices++;
                    // cout<<"Doing\n";
                    continue;
                }
                else{
                    for (int k = 0; k < no_offices; k++)
                    {   
                        // cout<<"DOiiiiing\t"<<k<<"\n";
                        if(arr[i][j]==0 && flag==0){
                            dist = distance(i,j,offices[k][0],offices[k][1]);
                            // cout<<"-->"<<dist;
                            flag=1;
                        }
                        else if(dist > distance(i,j,offices[k][0],offices[k][1])){
                            dist = distance(i,j,offices[k][0],offices[k][1]);
                            // cout<<"--**-->"<<dist;
                        }
                        

                    }
                    // cout<<"\n";
                    arr[i][j] = dist;
                    if(dist>max){
                        max = dist;
                        pos_x = i;
                        pos_y = j;
                    }
                    else if(dist==max){
                        pos_x = (pos_x + i)/2;
                        pos_y = (pos_y + j)/2;
                    }

                    
                }
            }
            
        }
        if(pos_x==-1 && pos_y==-1){
            cout<<"Case #"<<p+1<<": "<<res_max<<"\n";
            continue;
            
        }
        else{
            vector<int> temp_offices;
            temp_offices.push_back(pos_x);
            temp_offices.push_back(pos_y);
            offices.push_back(temp_offices);
            no_offices++;
            result[pos_x][pos_y] = 1;

        }

        pt_offices = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                flag=0;
                if(i==offices[pt_offices][0] && j==offices[pt_offices][1]){
                    pt_offices++;
                    continue;
                }
                else{
                    for (int k = 0; k < no_offices; k++)
                    {   
                        if(result[i][j]==0 && flag==0){
                            dist = distance(i,j,offices[k][0],offices[k][1]);
                            // cout<<"-->"<<dist;
                            flag=1;
                        }
                        else if(dist > distance(i,j,offices[k][0],offices[k][1])){
                            dist = distance(i,j,offices[k][0],offices[k][1]);
                            // cout<<"--**-->"<<dist;
                        }
                        

                    }
                    // cout<<"\n";
                    result[i][j] = dist;
                    if(dist>res_max){
                        res_max = dist;
                    }
                
                    
                }
            }
            
        }

        
        // for (int i = 0; i < r; i++)
        // {
        //     for (int j = 0; j < c; j++)
        //     {
        //         cout << arr[i][j];
        //     }
        //     cout<<"\n";
            
        // }
        // cout<<"HHHHHHHHHHHHHHHHHHHHHHHHHHH\n";
        // for (int i = 0; i < no_offices; i++)
        // {
        //     for (int j = 0; j < 2; j++)
        //     {
        //         cout << offices[i][j];
        //     }
        //     cout<<"\n";
            
        // }
        // for (int i = 0; i < r; i++)
        // {
        //     for (int j = 0; j < c; j++)
        //     {
        //         cout << result[i][j];
        //     }
        //     cout<<"\n";
            
        // }

            
        
        // cout<<"-----"<<pos_x<<pos_y<<"\n";
        cout<<"Case #"<<p+1<<": "<<res_max<<"\n";
    }
    
    
    return 0;
}