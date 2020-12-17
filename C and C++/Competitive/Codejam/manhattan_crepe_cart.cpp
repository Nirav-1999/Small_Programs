#include<bits/stdc++.h>


using namespace std;

int main(){

    int T;
    cin>>T;

    for (int case_number = 0; case_number < T; case_number++)
    {
        int P,Q,count,N_S,E_W,max_x = 0,xx,max_y = 0,yy,flag_x = 0,flag_y = 0,num_x=0,num_y=0;
        
        cin >> P >> Q;
        
        vector<vector <int>> pos(P, vector<int>(2));
        vector<char> direction(P);
        vector<int> x_list(Q+1,0);
        vector<int> y_list(Q+1,0);
        vector<int>::iterator it; 

        for (int i = 0; i < P; i++)
        {
            cin >> pos[i][0] >> pos[i][1] >> direction[i];
            
        }
        

        for (int i = 0; i < P; i++)
        {   
            // flag_y = 0, flag_x = 0;
            if(direction[i] == 'S' || direction[i] == 'N'){

                
                if (direction[i] == 'N')
                {
                    N_S = 1;
                }
                else
                {
                    N_S = -1;
                }
                
                count = pos[i][1] + N_S;
                // cout<<"This is for Y\n";

                while (count >= 0 && count <= Q)
                {
                    y_list[count] += 1;
                    // cout<<"Before: "<<yy<<"<-----"<<count<<"-----"<<flag_y<<"\n";

                    if(y_list[count] > max_y){
                        max_y = y_list[count];
                    }

                    // cout<<"Before: "<<yy<<"<-----"<<count<<"-----"<<flag_y<<"\n";
                    // for (int i = 0; i <= Q ; i++)
                    // {
                    //     cout<<y_list[i]<<"\t";
                    // }
                    // cout<<"\n";
                    count += N_S;
                }
            }

            else
            {
                if (direction[i] == 'E')
                {
                    E_W = 1;
                }
                else
                {
                    E_W = -1;
                }
                
                count = pos[i][0] + E_W;
                // cout<<"This is for X\n";

                while (count >= 0 && count <= Q)
                {
                    x_list[count] += 1;

                    if(x_list[count] >= max_x){
                        max_x = x_list[count];
                    }
                    count += E_W;

                }
                    // cout<<xx<<"<-----"<<count<<"-----"<<flag_x<<"\n";

                    // for (int i = 0; i <= Q ; i++)
                    // {
                    //     cout<<x_list[i]<<"\t";
                    // }
                    // cout<<"\n";
            }
            
        }
    
    it = find(x_list.begin(), x_list.end(), max_x); 
    xx = it - x_list.begin();
    it = find(y_list.begin(), y_list.end(), max_y); 
    yy = it - y_list.begin();


    cout<<"Case #"<<case_number+1<<": "<<xx<<" "<<yy<<" \n";

            
    }

    return 0;
}